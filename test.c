#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main() {
    DeviceInfo device = initialize_device();

    DeviceStatus *status = malloc(sizeof(DeviceStatus));

    get_status(&device, status);

    printf("Done!");
}
