#include "drivers/arctis_9.h"

const device_identifier arctis_9 = {
    .name = "Arctis 9",
    .product_id = 0x12c2,
    .write_bytes = {0x00, 0x20},
    .interface_number = 0,
    .battery_percentage_index = 3,
    .charging_status_index = 4,
    .connected_status_index = 1,
    .usage_page_and_id = {},
    .read_buffer_size = 12,
    .battery_range = {0x64, 0xa5}
};
