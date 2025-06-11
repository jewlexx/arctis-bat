#include <stdio.h> // printf
#include <string.h>
#include <stdlib.h>

#include <hidapi/hidapi.h> // hidapi

#include <drivers.h> // drivers.h

#include "device.h" // device.h

#define MAX_STR 255

int main(void)
{
	int res = 0;

	// Initialize the hidapi library
	res = hid_init();

	const device_identifier *device_id;
	// Open the device using the VID, PID,
	// and optionally the Serial number.
	hid_device *handle;

	for (int i = 0; i < HEADPHONE_COUNT; i++)
	{
		const device_identifier *temp_device_id = all_headphone_models[i];
		hid_device *temp_handle = hid_open(VENDOR_ID, temp_device_id->product_id, NULL);

		if (temp_handle)
		{
			handle = temp_handle;
			device_id = temp_device_id;
			printf("Found device! (PID: 0x%04x)\n", device_id->product_id);

			wchar_t wstr[MAX_STR];

			// Read the Product String
			res = hid_get_product_string(handle, wstr, MAX_STR);

			size_t manustring_length = wcslen(wstr);
			char *manustring = malloc(manustring_length * sizeof(wchar_t));
			wcstombs(manustring, wstr, manustring_length);

			if (strncmp(manustring, device_id->name, strlen(device_id->name)) == 0) {
				printf("Product string matches expected model: %s\n", manustring);
			} else {
				printf("Device does not match expected model: %s != %s\n", device_id->name, manustring);
				printf("Trying next device...\n");
				hid_close(handle);
				handle = NULL;
				continue; // Skip to the next device
			}

			res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
			printf("Manufacturer String: %ls\n", wstr);

			break;
		}
	}

	if (!handle)
	{
		printf("Unable to find any supported devices\n");
		hid_exit();
		return 1;
	}


	device_status *status = malloc(sizeof(device_status));

    if (get_device_status(handle, device_id, status) < 0) {
        printf("Failed to get device status\n");
        hid_close(handle);
        hid_exit();
        return 1;
    }


    const char* charging_status = get_pretty_charging_status(status->status);
    printf("Charging Status: %s (%d)\n", charging_status, status->status);
    printf("Battery Level: %.2f%%\n", status->battery_level);

	// Close the device
	hid_close(handle);

	// Finalize the hidapi library
	res = hid_exit();

	return res;
}
