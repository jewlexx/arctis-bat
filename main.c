#include <stdio.h> // printf
#include <wchar.h> // wchar_t
#include <stdlib.h> // malloc, free

#include <hidapi/hidapi.h> // hidapi

#include "device.h" // device.h

#define MAX_STR 255

int main(int argc, char* argv[])
{
	int res;
	unsigned char buf[65];
	wchar_t wstr[MAX_STR];
	hid_device *handle;
	int i;

	// Initialize the hidapi library
	res = hid_init();

	// Open the device using the VID, PID,
	// and optionally the Serial number.
	handle = hid_open(VENDOR_ID, PRODUCT_ID, NULL);
	if (!handle) {
		printf("Unable to open device\n");
		hid_exit();
 		return 1;
	}

	// Read the Manufacturer String
	res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
	printf("Manufacturer String: %ls\n", wstr);

	// Read the Product String
	res = hid_get_product_string(handle, wstr, MAX_STR);
	printf("Product String: %ls\n", wstr);

	// Read the Serial Number String
	res = hid_get_serial_number_string(handle, wstr, MAX_STR);
	printf("Serial Number String: (%d) %ls\n", wstr[0], wstr);

	// Read Indexed String 1
	// res = hid_get_indexed_string(handle, 1, wstr, MAX_STR);
	// printf("Indexed String 1: %ls\n", wstr);

	struct device_status *status = malloc(sizeof(struct device_status));

    if (get_device_status(handle, status) < 0) {
        printf("Failed to get device status\n");
        free(status);
        hid_close(handle);
        hid_exit();
        return 1;
    }


    printf("Charging Status: %d\n", status->status);
    printf("Battery Level: %.2f%%\n", status->battery_level);

	// Close the device
	hid_close(handle);

	// Finalize the hidapi library
	res = hid_exit();

	return 0;
}

