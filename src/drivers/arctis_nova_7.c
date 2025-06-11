#include "include/drivers/arctis_nova_7.h"

const device_identifier arctis_nova_7 = {
    .name = "Arctis Nova 7",
    .product_id = 0x2202,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 2,
    .charging_status_index = 3,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x1},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};
