#include <stdio.h> // printf
#include <string.h>
#include <stdlib.h>

#include <hidapi/hidapi.h> // hidapi

#include <drivers.h> // drivers.h

#include "device.h" // device.h

int main(void)
{
	int res = 0;
	const device_identifier *device_id;
	hid_device *handle = NULL;

	// Initialize the hidapi library
	if (hid_init() < 0)
	{
		res = -1;
		goto cleanup;
	}

	res = get_device(device_id, &handle);

	if (!handle)
	{
		printf("Unable to find any supported devices\n");
		res = 1;
		goto cleanup;
	}

	device_status *status = malloc(sizeof(device_status));

	if (get_device_status(handle, device_id, status) < 0)
	{
		printf("Failed to get device status\n");
		res = 1;
		goto cleanup;
	}

	const char *charging_status = get_pretty_charging_status(status->status);
	printf("Charging Status: %s (%d)\n", charging_status, status->status);
	printf("Battery Level: %.2f%%\n", status->battery_level);

	free(status);

cleanup:
	if (res < 0)
	{
		const wchar_t *error = hid_error(NULL); // Get the last error
		printf("An error occurred: %ls\n", error);
	}

	// Close the device
	hid_close(handle);

	// Finalize the hidapi library
	if (hid_exit() < 0)
	{
		res = -1;
	}

	return res;
}
