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

typedef struct {
    enum charging_status status;
    float battery_level;
} device_status;

int get_device_status(hid_device *handle, device_status *status);
