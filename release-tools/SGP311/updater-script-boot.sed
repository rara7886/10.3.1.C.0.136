ui_print("");
ui_print("");
ui_print("------------------------------------------------");
ui_print("@VERSION");
ui_print("    install Custom Kernel & Modules");
ui_print("");
ui_print("    by rara7886");
ui_print("------------------------------------------------");
ui_print("");
show_progress(1.000000, 0);

ui_print("flashing boot image...");
package_extract_file("boot.img", "/dev/block/platform/msm_sdcc.1/by-name/boot");
set_progress(0.330000);

ui_print("Mount device /system dir");
run_program("/sbin/busybox", "mount", "/system");
 
ui_print("Extract ZIP in system to device /system dir");
package_extract_dir("system", "/system");

ui_print("Set Permission");
set_perm(0, 0, 0644, "system/etc/firmware/wlan/prima/WCNSS_cfg.dat");
set_perm(0, 0, 0644, "system/etc/firmware/wlan/prima/WCNSS_qcom_cfg.ini");
#set_perm(0, 0, 0644, "system/etc/firmware/wlan/prima/WCNSS_qcom_wlan_nv.bin");

set_perm(0, 0, 0644, "system/lib/modules/prima/prima_wlan.ko");
set_perm(0, 0, 0644, "system/lib/modules/cfg80211.ko");
#set_perm(0, 0, 0644, "system/lib/modules/texfat.ko");
set_perm(0, 0, 0644, "system/lib/modules/reset_modem.ko");
set_perm(0, 0, 0644, "system/lib/modules/dma_test.ko");
set_perm(0, 0, 0644, "system/lib/modules/msm-buspm-dev.ko");
set_perm(0, 0, 0644, "system/lib/modules/ansi_cprng.ko");
set_perm(0, 0, 0644, "system/lib/modules/lcd.ko");
set_perm(0, 0, 0644, "system/lib/modules/adsprpc.ko");
set_perm(0, 0, 0644, "system/lib/modules/eeprom_93cx6.ko");
set_perm(0, 0, 0644, "system/lib/modules/scsi_wait_scan.ko");
set_perm(0, 0, 0644, "system/lib/modules/spidev.ko");
set_perm(0, 0, 0644, "system/lib/modules//ks8851.ko");
set_perm(0, 0, 0644, "system/lib/modules/gspca_main.ko");
set_perm(0, 0, 0644, "system/lib/modules/radio-iris-transport.ko");
set_perm(0, 0, 0644, "system/lib/modules/mmc_test.ko");
set_perm(0, 0, 0644, "system/lib/modules/qcedev.ko");
set_perm(0, 0, 0644, "system/lib/modules/qce40.ko");
set_perm(0, 0, 0644, "system/lib/modules/qcrypto.ko");
set_perm(0, 0, 0644, "system/lib/modules/mckernelapi.ko");
set_perm(0, 0, 0644, "system/lib/modules/mcdrvmodule.ko");
set_perm(0, 0, 0644, "system/lib/modules/oprofile.ko");
#set_perm(0, 0, 0644, "system/lib/modules/exfat_core.ko");
#set_perm(0, 0, 0644, "system/lib/modules/exfat_fs.ko");



ui_print("flash complete. Enjoy!");
set_progress(1.000000);

