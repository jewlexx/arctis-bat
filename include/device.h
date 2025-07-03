#pragma once
#include <stdint.h>
#include <stddef.h>
#include <devices.h>
#include <hidapi/hidapi.h>

typedef enum
{
    DISCONNECTED = 0x00,
    CHARGING = 0x01,
    DISCHARGING = 0x03,
} charging_status;

typedef struct
{
    charging_status status;
    float battery_level;
} device_status;

int get_device(device_identifier *device_id, hid_device **handle);

int get_device_status(void *handle, const device_identifier *device_id, device_status *status);

const char *get_pretty_charging_status(charging_status status);
