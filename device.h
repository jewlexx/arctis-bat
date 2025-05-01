#include <hidapi/hidapi.h>

// Steelseries Vendor ID
#define VENDOR_ID 0x1038
#define PRODUCT_ID 0x2202

enum charging_status
{
    DISCONNECTED = 0x00,
    CHARGING = 0x01,
    DISCHARGING = 0x03,
};

struct device_status {
    enum charging_status status;
    float battery_level;
};

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