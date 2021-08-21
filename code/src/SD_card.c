//// interface for SD card that sets up drivers, FATFS and virtual file system (VFS)

#include "globals.h"


void SD_card_init(){
    // initialise SD peripherial host
    sdmmc_host_t card_host = SDMMC_HOST_DEFAULT(); // used as an API for higher protocol stack layers to interact with
    sdmmc_host_init();

    // initialise slot 0
    sdmmc_slot_config_t slot_cfg = SDMMC_SLOT_CONFIG_DEFAULT();
    sdmmc_host_init_slot(SDMMC_HOST_SLOT_0, &slot_cfg);

    // initialise SD protocol drivers
    sdmmc_card_t *card_info = NULL; // "handle" for the card
    sdmmc_card_init(&card_host, card_info);

    // link a drive identification number to a path using VFS
    FATFS *file_system;
    esp_vfs_fat_register(SD_BASE_PATH, 0, 1, &file_system); // register SD_BASE_PATH to drive 0, max 1 file open at once

    // register SD drivers to FATFS (mount SD card)

    ff_diskio_register_sdmmc(0, card_info); // register card to drive 0
    f_mount(file_system, 0, 0);


    sdmmc_card_print_info(stdout, card_info);
}
