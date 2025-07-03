#include "devices/arctis_7_2017.h"

const device_identifier arctis_7_2017 = {
    .name = "Arctis 7 2017",
    .product_id = 0x1260,
    .write_bytes = {0x06, 0x18},
    .interface_number = 5,
    .battery_percentage_index = 2,
    .charging_status_index = 0,
    .connected_status_index = 0,
    .usage_page_and_id = {},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};
