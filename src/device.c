#include <hidapi/hidapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "device.h"

#define MAX_STR 255

int get_device(device_identifier *device_id, hid_device **handle)
{
    for (int i = 0; i < HEADPHONE_COUNT; i++)
    {
        const device_identifier *temp_device_id = all_headphone_models[i];
        hid_device *temp_handle = hid_open(VENDOR_ID, temp_device_id->product_id, NULL);

        if (temp_handle)
        {
            *handle = temp_handle;
            *device_id = *temp_device_id;
            printf("Found device! (PID: 0x%04x)\n", device_id->product_id);

            wchar_t wstr[MAX_STR];

            // Read the Product String
            int res = hid_get_product_string(*handle, wstr, MAX_STR);

            if (res == 0)
            {
                size_t manustring_length = wcslen(wstr);
                char *manustring = malloc(manustring_length * sizeof(wchar_t));
                wcstombs(manustring, wstr, manustring_length);

                if (strncmp(manustring, device_id->name, strlen(device_id->name)) == 0)
                {
                    printf("Product string matches expected model: %s\n", manustring);
                }
                else
                {
                    printf("Device does not match expected model: %s != %s\n", device_id->name, manustring);
                    printf("Trying next device...\n");
                    hid_close(*handle);
                    *handle = NULL;
                    continue; // Skip to the next device
                }

                free(manustring);
            }
            else
            {
                return res;
            }

            res = hid_get_manufacturer_string(*handle, wstr, MAX_STR);

            if (res == 0)
            {
                printf("Manufacturer String: %ls\n", wstr);
            }
            else
            {
                return res;
            }

            break;
        }
    }

    return 0;
}

int get_device_status(void *handle, const device_identifier *device_id, device_status *status)
{
    handle = (hid_device *)handle;
    if (handle == NULL)
    {
        return -1;
    }

    int res;

    res = hid_write(handle, device_id->write_bytes, 2);

    unsigned char buf[4];
    // Read requested state
    res = hid_read(handle, buf, 4);

    if (res < 0)
    {
        return -1;
    }

    status->status = (charging_status)buf[device_id->charging_status_index];
    status->battery_level = ((float)buf[device_id->battery_percentage_index] / 4.0f) * 100.0f;

    return 0;
}

const char *get_pretty_charging_status(charging_status status)
{
    switch (status)
    {
    case CHARGING:
        return "Charging";
    case DISCHARGING:
        return "Discharging";
    default:
        return "Disconnected";
    }
}
