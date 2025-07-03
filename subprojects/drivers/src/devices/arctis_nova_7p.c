#include "devices/arctis_nova_7p.h"

const device_identifier arctis_nova_7p = {
    .name = "Arctis Nova 7P",
    .product_id = 0x220a,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 2,
    .charging_status_index = 3,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x01},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};
