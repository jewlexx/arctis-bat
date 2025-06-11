#include "drivers/include/drivers/arctis_pro_wireless.h"

const device_identifier arctis_pro_wireless = {
    .name = "Arctis Pro Wireless",
    .product_id = 0x1290,
    .write_bytes = {0x40, 0xaa},
    .interface_number = 0,
    .battery_percentage_index = 0,
    .charging_status_index = 0,
    .connected_status_index = 0,
    .usage_page_and_id = {},
    .read_buffer_size = 2,
    .battery_range = {0x00, 0x04}
};
