#include "drivers/include/drivers/arctis_7_2019.h"

const device_identifier arctis_7_2019 = {
    .name = "Arctis 7 2019",
    .product_id = 0x12ad,
    .write_bytes = {0x06, 0x18},
    .interface_number = 5,
    .battery_percentage_index = 2,
    .charging_status_index = 0,
    .connected_status_index = 0,
    .usage_page_and_id = {},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};
