#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/usb/usb_device.h>

const struct device *dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));

int main(void)
{
    if (!device_is_ready(dev)) {
        printk("Device not ready\n");
        return -1;
    }

    // INFO: only necessary with adafruit
    if (usb_enable(NULL)) {
        printk("USB enable failed\n");
        return -1;
    }

    printk("This is the encoder sample code!\n");
    while (1) {
        k_sleep(K_SECONDS(3));
        printk("This is the encoder sample code!\n");
    }
}
