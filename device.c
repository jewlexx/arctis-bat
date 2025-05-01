#include <hidapi/hidapi.h>

#include "device.h"

int get_device_status(hid_device *handle, struct device_status *status)
{
    unsigned char buf[4];
    int res;

    unsigned char request_buf[2] = { 0x00, 0xb0 };
    res = hid_write(handle, request_buf, 2);

    // Read requested state
    res = hid_read(handle, buf, 4);

    if (res < 0) {
        return -1;
    }

    status->status = (enum charging_status)buf[3];
    status->battery_level = ((float)buf[2] / 4.0f) * 100.0f;

    return 0;
}