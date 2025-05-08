#include <hidapi/hidapi.h>

// Steelseries Vendor ID
#define VENDOR_ID 0x1038
#define PRODUCT_ID 0x2202

typedef enum
{
    DISCONNECTED = 0x00,
    CHARGING = 0x01,
    DISCHARGING = 0x03,
} charging_status;

typedef struct {
    charging_status status;
    float battery_level;
} device_status;

int get_device_status(hid_device *handle, device_status *status);

char* get_pretty_charging_status(charging_status status);
