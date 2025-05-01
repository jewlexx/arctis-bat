#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main() {
    printf("Initializing!");

    DeviceInfo device = initialize_device();

    printf("Initialized!");

    DeviceStatus *status = malloc(sizeof(DeviceStatus));

    get_status(&device, status);

    printf("Done!");
}
