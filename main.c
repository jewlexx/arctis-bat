#include <stdio.h> // printf
#include <wchar.h> // wchar_t
#include <stdlib.h> // malloc, free

#include <hidapi/hidapi.h> // hidapi

#include "device.h" // device.h

#define MAX_STR 255

int main(int argc, char* argv[])
{
	int res = 0;

	// Initialize the hidapi library
	res = hid_init();

	// Open the device using the VID, PID,
	// and optionally the Serial number.
	hid_device *handle = hid_open(VENDOR_ID, PRODUCT_ID, NULL);
	if (!handle) {
		printf("Unable to open device\n");
		hid_exit();
 		return 1;
	}

	wchar_t wstr[MAX_STR];

	// Read the Manufacturer String
	res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
	printf("Manufacturer String: %ls\n", wstr);

	// Read the Product String
	res = hid_get_product_string(handle, wstr, MAX_STR);
	printf("Product String: %ls\n", wstr);

	device_status status = {};

    if (get_device_status(handle, &status) < 0) {
        printf("Failed to get device status\n");
        hid_close(handle);
        hid_exit();
        return 1;
    }


    char* charging_status = get_pretty_charging_status(status.status);
    printf("Charging Status: %s (%d)\n", charging_status, status.status);
    printf("Battery Level: %.2f%%\n", status.battery_level);

	// Close the device
	hid_close(handle);

	// Finalize the hidapi library
	res = hid_exit();

	return res;
}
