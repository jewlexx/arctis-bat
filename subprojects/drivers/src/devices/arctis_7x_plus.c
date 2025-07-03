#include "devices/arctis_7x_plus.h"

const device_identifier arctis_7x_plus = {
    .name = "Arctis 7X Plus",
    .product_id = 0x2216,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 2,
    .charging_status_index = 3,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x01},
    .read_buffer_size = 6,
    .battery_range = {0x00, 0x04}
};
