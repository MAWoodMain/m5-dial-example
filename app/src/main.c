/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <app_version.h>

#include <zephyr/logging/log.h>
#include <zephyr/drivers/display.h>

LOG_MODULE_REGISTER(main, CONFIG_APP_LOG_LEVEL);

int main(void)
{
    const struct device *display_dev;
    struct display_capabilities capabilities;
	printk("Zephyr Example Application %s\n", APP_VERSION_STRING);

    do {
        display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
        if (!device_is_ready(display_dev)) {
            LOG_ERR("Device %s not found. Aborting sample.",
                    display_dev->name);
            break;
        }

        LOG_INF("Display sample for %s", display_dev->name);
        display_get_capabilities(display_dev, &capabilities);
        LOG_INF("Display resolution %dx%d, orientation: %d", capabilities.x_resolution, capabilities.y_resolution,
                capabilities.current_orientation);

        while (1) {

            printk("Hello!\n");

            k_sleep(K_MSEC(1000));
        }
    } while(false);

	return 0;
}

