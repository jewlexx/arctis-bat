#include "include/drivers/arctis_1_xbox.h"

const device_identifier arctis_1_xbox = {
    .name = "Arctis 1 Xbox",
    .product_id = 0x12b6,
    .write_bytes = {0x06, 0x12},
    .interface_number = 3,
    .battery_percentage_index = 3,
    .charging_status_index = 4,
    .connected_status_index = 0,
    .usage_page_and_id = {0xff43, 0x202},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};
