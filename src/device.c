#include <hidapi/hidapi.h>

#include "include/device.h"

int get_device_status(void *handle, const device_identifier *device_id, device_status *status)
{
    handle = (hid_device *)handle;
    if (handle == NULL) {
        return -1;
    }

    int res;

    res = hid_write(handle, device_id->write_bytes, 2);

    unsigned char buf[4];
    // Read requested state
    res = hid_read(handle, buf, 4);

    if (res < 0) {
        return -1;
    }

    status->status = (charging_status)buf[device_id->charging_status_index];
    status->battery_level = ((float)buf[device_id->battery_percentage_index] / 4.0f) * 100.0f;

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
