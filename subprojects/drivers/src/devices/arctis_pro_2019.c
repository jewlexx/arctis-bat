#include "devices/arctis_pro_2019.h"

const device_identifier arctis_pro_2019 = {
    .name = "Arctis Pro 2019",
    .product_id = 0x1252,
    .write_bytes = {0x06, 0x18},
    .interface_number = 5,
    .battery_percentage_index = 2,
    .charging_status_index = 0,
    .connected_status_index = 0,
    .usage_page_and_id = {},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};
