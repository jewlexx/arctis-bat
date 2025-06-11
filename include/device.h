#pragma once
#include <stdint.h>
#include <stddef.h>

// Steelseries Vendor ID
#define VENDOR_ID 0x1038

typedef struct {
    const char *name;
    uint16_t product_id;
    uint8_t write_bytes[2];
    int32_t interface_number;
    int battery_percentage_index;
    int charging_status_index;
    int connected_status_index;
    uint16_t usage_page_and_id[2];
    int read_buffer_size;
    uint16_t battery_range[2];
} device_identifier;

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

int get_device_status(void *handle, const device_identifier *device_id, device_status *status);

const char* get_pretty_charging_status(charging_status status);

