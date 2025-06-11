#include "include/drivers/arctis_nova_5.h"

const device_identifier arctis_nova_5 = {
    .name = "Arctis Nova 5",
    .product_id = 0x2232,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 3,
    .charging_status_index = 4,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x01},
    .read_buffer_size = 64,
    .battery_range = {0x00, 0x64}
};
