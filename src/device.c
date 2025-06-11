#include <hidapi/hidapi.h>

#include "include/device.h"

int get_device_status(void *handle, device_status *status)
{
    handle = (hid_device *)handle;
    if (handle == NULL) {
        return -1;
    }

    unsigned char buf[4];
    int res;

    unsigned char request_buf[2] = { 0x00, 0xb0 };
    res = hid_write(handle, request_buf, 2);

    // Read requested state
    res = hid_read(handle, buf, 4);

    if (res < 0) {
        return -1;
    }

    status->status = (charging_status)buf[3];
    status->battery_level = ((float)buf[2] / 4.0f) * 100.0f;

    return 0;
}

const char* get_pretty_charging_status(charging_status status) {
    switch (status) {
        case CHARGING:
            return "Charging";
        case DISCHARGING:
            return "Discharging";
        default:
            return "Disconnected";
    }
}
