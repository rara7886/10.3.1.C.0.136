#!/bin/bash
TARGET_DEVICE=SGP311
BUILD_LOCALVERSION=1.0.0

# set kernel option
   export KERNEL_BASEADDRESS=0x80200000
export KERNEL_RAMDISK_OFFSET=0x82200000

case "$TARGET_DEVICE" in
  "SGP311"  ) export KERNEL_DEFCONFIG=fusion3_pollux_windy_defconfig ;;
esac

export IMG_MAX_SIZE=20447232

KERNEL_DIR=$PWD
export RAMDISK_SRC_DIR=$KERNEL_DIR/ramdisk
export RAMDISK_TMP_DIR=$KERNEL_DIR/tmp-ramdisk
IMAGE_NAME=boot

BIN_DIR=$KERNEL_DIR/../out/$TARGET_DEVICE/bin
OBJ_DIR=$KERNEL_DIR/../out/$TARGET_DEVICE/obj
mkdir -p $BIN_DIR
mkdir -p $OBJ_DIR

TOOLCHAIN_DIR=~/android
echo ""
echo "======================"
echo "   Install Building Tools"
echo "======================"
if [ ! -d /usr/lib/jvm ]; then
    sudo apt-get install git-core gnupg \
  flex bison gperf build-essential zip curl \
  zlib1g-dev libncurses5-dev x11proto-core-dev \
  libx11-dev libreadline6-dev libgl1-mesa-dev tofrodos \
  python-markdown libxml2-utils xsltproc \
  libsdl-dev libesd0-dev libwxgtk3.0-dev \
  openjdk-8-jre-headless lzop
    echo "Installed Building Tools"
else
    echo "Install Pass"
fi

echo ""
echo "======================="
echo "    BUILD START"
echo "======================="

if [ ! -n "$1" ]; then
  echo ""
  read -p "select build? [(a)ll/(u)pdate/(i)mage default:update] " BUILD_SELECT
else
  BUILD_SELECT=$1
fi

# copy RAMDISK
echo ""
echo "=====> COPY RAMDISK"

    echo copy $RAMDISK_SRC_DIR to $RAMDISK_TMP_DIR

    if [ -d $RAMDISK_TMP_DIR ]; then
        rm -rf $RAMDISK_TMP_DIR
    fi
    mkdir $RAMDISK_TMP_DIR
    cp -r $RAMDISK_SRC_DIR/* $RAMDISK_TMP_DIR
    rm -rf $RAMDISK_TMP_DIR/.git
    find $RAMDISK_TMP_DIR -name .gitkeep | xargs rm --force
    find $RAMDISK_TMP_DIR -name .gitignore | xargs rm --force

# install cross compiler

    if [ ! -d $TOOLCHAIN_DIR/arm-eabi-4.6 ]; then
        mkdir -p $TOOLCHAIN_DIR/arm-eabi-4.6
        cd $TOOLCHAIN_DIR
	git clone https://android.googlesource.com/platform/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6
	cd $KERNEL_DIR
    fi

    echo Use toolchsin $TOOLCHAIN_DIR/arm-eabi-4.6
    export CROSS_COMPILE=$TOOLCHAIN_DIR/arm-eabi-4.6/bin/arm-eabi-

# make start
if [ "$BUILD_SELECT" = 'all' -o "$BUILD_SELECT" = 'a' ]; then
  echo ""
  echo "=====> CLEANING..."
  #make clean
  rm -rf $KERNEL_DIR/out
  mkdir -p $BIN_DIR
  mkdir -p $OBJ_DIR
  #cp -f ./arch/arm/configs/$KERNEL_DEFCONFIG $OBJ_DIR/.config
  make -C $PWD O=$OBJ_DIR ARCH=arm CROSS_COMPILE=$CROSS_COMPILE $KERNEL_DEFCONFIG || exit -1
fi

if [ "$BUILD_SELECT" != 'image' -a "$BUILD_SELECT" != 'i' ]; then
  echo ""
  echo "=====> BUILDING..."
  if [ -e $OBJ_DIR/make.log ]; then
    mv $OBJ_DIR/make.log $OBJ_DIRmake_old.log
  fi
  nice -n 10 make O=$OBJ_DIR ARCH=arm CROSS_COMPILE=$CROSS_COMPILE -j12 2>&1 | tee $OBJ_DIR/make.log
fi

# check compile error
COMPILE_ERROR=`grep 'error:' $OBJ_DIR/make.log`
if [ "$COMPILE_ERROR" ]; then
  echo ""
  echo "=====> ERROR"
  grep 'error:' $OBJ_DIR/make.log
  exit -1
fi


echo ""
echo "=====> CREATE RELEASE IMAGE"
# clean release dir
if [ `find $BIN_DIR -type f | wc -l` -gt 0 ]; then
  rm -rf $BIN_DIR/*
fi
mkdir -p $BIN_DIR

# copy zImage -> kernel
cp $OBJ_DIR/arch/arm/boot/zImage $BIN_DIR/kernel

# create boot image
    if [ ! -d $KERNEL_DIR/ramdisk/lib ]; then
    	mkdir $KERNEL_DIR/ramdisk/lib
    fi
    cp $OBJ_DIR/fs/exfat/exfat.ko $KERNEL_DIR/ramdisk/lib/texfat.ko
    find $KERNEL_DIR/ramdisk/lib -name "*.ko" | xargs -i $CROSS_COMPILE"strip" --strip-unneeded {}

    cd $RAMDISK_TMP_DIR
    find . | cpio --quiet -H newc -o | gzip > $BIN_DIR/ramdisk-$IMAGE_NAME.img
    cd $KERNEL_DIR
    $KERNEL_DIR/release-tools/mkbootimg \
       --cmdline "androidboot.hardware=qcom user_debug=31 msm_rtb.filter=0x3F ehci-hcd.park=3 console=tty0,115200 fbcon=rotate:0 fbcon=font:VGA8x16 vmalloc=400M androidboot.emmc=true" \
       --base $KERNEL_BASEADDRESS --ramdiskaddr $KERNEL_RAMDISK_OFFSET --kernel $BIN_DIR/kernel \
       --ramdisk $BIN_DIR/ramdisk-$IMAGE_NAME.img --output $BIN_DIR/$IMAGE_NAME.img
    echo "  $BIN_DIR/$IMAGE_NAME.img"
    rm $BIN_DIR/ramdisk-$IMAGE_NAME.img
    rm $BIN_DIR/kernel 
    rm -r $RAMDISK_TMP_DIR
    mv $KERNEL_DIR/.log $OBJ_DIR/.log

#check image size
img_size=`wc -c $BIN_DIR/$IMAGE_NAME.img | awk '{print $1}'`
if [ $img_size -gt $IMG_MAX_SIZE ]; then
    echo "FATAL: $IMAGE_NAME image size over. image size = $img_size > $IMG_MAX_SIZE byte"
    rm $BIN_DIR/$IMAGE_NAME.img
    exit -1
fi


# create cwm include kernel modules
    tmpcwm=$KERNEL_DIR/../tmp
    if [ -d $tmpcwm ]; then
        rm -rf $tmpcwm
    fi
    mkdir -p $tmpcwm/META-INF/com/google/android
    cp $BIN_DIR/$IMAGE_NAME.img $tmpcwm/
    cp $KERNEL_DIR/release-tools/update-binary $tmpcwm/META-INF/com/google/android/
    sed -e "s/@VERSION/$BUILD_LOCALVERSION/g" $KERNEL_DIR/release-tools/$TARGET_DEVICE/updater-script-$IMAGE_NAME.sed > $tmpcwm/META-INF/com/google/android/updater-script
    

    mkdir -p $tmpcwm/system/lib/modules/prima
    find $OBJ_DIR -name "*.ko" | xargs -i cp {} $tmpcwm/system/lib/modules/
    find $tmpcwm/system/lib/modules -name "*.ko" | xargs -i $CROSS_COMPILE"strip" --strip-unneeded {}
    mv $tmpcwm/system/lib/modules/wlan.ko $tmpcwm/system/lib/modules/prima/prima_wlan.ko
    #mv $tmpcwm/system/lib/modules/exfat.ko $tmpcwm/system/lib/modules/texfat.ko
    #rm $tmpcwm/system/lib/modules/texfat.ko
    
orginal(){
    cp $OBJ_DIR/drivers/staging/prima/wlan.ko $tmpcwm/system/lib/modules/prima/prima_wlan.ko
    $CROSS_COMPILE"strip" --strip-unneeded $tmpcwm/system/lib/modules/prima/prima_wlan.ko

    cp $OBJ_DIR/net/wireless/cfg80211.ko $tmpcwm/system/lib/modules/
    $CROSS_COMPILE"strip" --strip-unneeded $tmpcwm/system/lib/modules/cfg80211.ko

    cp $OBJ_DIR/fs/exfat/exfat.ko $tmpcwm/system/lib/modules/texfat.ko
    $CROSS_COMPILE"strip" --strip-unneeded $tmpcwm/system/lib/modules/texfat.ko
}

    mkdir -p $tmpcwm/system/etc/firmware/wlan/prima/
    cp $KERNEL_DIR/drivers/staging/prima/firmware_bin/WCNSS_cfg.dat $tmpcwm/system/etc/firmware/wlan/prima/
    cp $KERNEL_DIR/drivers/staging/prima/firmware_bin/WCNSS_qcom_cfg.ini $tmpcwm/system/etc/firmware/wlan/prima/
    # cp $KERNEL_DIR/drivers/staging/prima/firmware_bin/WCNSS_qcom_wlan_nv.bin $tmpcwm/system/etc/firmware/wlan/prima/

    cd $tmpcwm
    zip -rq ../cwm.zip ./* && cd ../
    SIGNAPK_DIR=$KERNEL_DIR/release-tools/signapk
    cd $KERNEL_DIR
    java -jar $SIGNAPK_DIR/signapk.jar $SIGNAPK_DIR/testkey.x509.pem $SIGNAPK_DIR/testkey.pk8 $tmpcwm/../cwm.zip $BIN_DIR/$BUILD_LOCALVERSION-$IMAGE_NAME-signed.zip
    rm $tmpcwm/../cwm.zip
    rm -rf $tmpcwm
    echo "  $BIN_DIR/$BUILD_LOCALVERSION-$IMAGE_NAME-signed.zip"


cd $KERNEL_DIR

echo ""
echo "====================================================================="
echo "    BUILD COMPLETED"
echo "====================================================================="
exit 0
