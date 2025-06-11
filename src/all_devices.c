#include "include/all_devices.h"

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

const device_identifier arctis_pro_gamedac = {
    .name = "Arctis Pro GameDac",
    .product_id = 0x1280,
    .write_bytes = {0x06, 0x18},
    .interface_number = 5,
    .battery_percentage_index = 2,
    .charging_status_index = 0,
    .connected_status_index = 0,
    .usage_page_and_id = {},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};

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

const device_identifier arctis_1_wireless = {
    .name = "Arctis 1 Wireless",
    .product_id = 0x12b3,
    .write_bytes = {0x06, 0x12},
    .interface_number = 3,
    .battery_percentage_index = 3,
    .charging_status_index = 4,
    .connected_status_index = 0,
    .usage_page_and_id = {0xff43, 0x202},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};

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

const device_identifier arctis_7x = {
    .name = "Arctis 7X",
    .product_id = 0x12d7,
    .write_bytes = {0x06, 0x12},
    .interface_number = 3,
    .battery_percentage_index = 3,
    .charging_status_index = 4,
    .connected_status_index = 0,
    .usage_page_and_id = {0xff43, 0x202},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};

const device_identifier arctis_7_plus = {
    .name = "Arctis 7 Plus",
    .product_id = 0x220e,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 2,
    .charging_status_index = 3,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x1},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};

const device_identifier arctis_7p_plus = {
    .name = "Arctis 7P Plus",
    .product_id = 0x2212,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 2,
    .charging_status_index = 3,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x1},
    .read_buffer_size = 6,
    .battery_range = {0x00, 0x04}
};

const device_identifier arctis_7x_plus = {
    .name = "Arctis 7X Plus",
    .product_id = 0x2216,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 2,
    .charging_status_index = 3,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x1},
    .read_buffer_size = 6,
    .battery_range = {0x00, 0x04}
};

const device_identifier arctis_7_destiny_plus = {
    .name = "Arctis 7 Destiny Plus",
    .product_id = 0x2236,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 2,
    .charging_status_index = 3,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x1},
    .read_buffer_size = 6,
    .battery_range = {0x00, 0x04}
};

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

const device_identifier arctis_nova_7x = {
    .name = "Arctis Nova 7X",
    .product_id = 0x2206,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 2,
    .charging_status_index = 3,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x1},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};

const device_identifier arctis_nova_7x_v2 = {
    .name = "Arctis Nova 7X v2",
    .product_id = 0x2258,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 2,
    .charging_status_index = 3,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x1},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};

const device_identifier arctis_nova_7p = {
    .name = "Arctis Nova 7P",
    .product_id = 0x220a,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 2,
    .charging_status_index = 3,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x1},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};

const device_identifier arctis_nova_7_diablo_iv = {
    .name = "Arctis Nova 7 Diablo IV",
    .product_id = 0x223a,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 2,
    .charging_status_index = 3,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x1},
    .read_buffer_size = 8,
    .battery_range = {0x00, 0x04}
};

const device_identifier arctis_nova_5 = {
    .name = "Arctis Nova 5",
    .product_id = 0x2232,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 3,
    .charging_status_index = 4,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x1},
    .read_buffer_size = 64,
    .battery_range = {0x00, 0x64}
};

const device_identifier arctis_nova_5x = {
    .name = "Arctis Nova 5X",
    .product_id = 0x2253,
    .write_bytes = {0x00, 0xb0},
    .interface_number = 3,
    .battery_percentage_index = 3,
    .charging_status_index = 4,
    .connected_status_index = 0,
    .usage_page_and_id = {0xffc0, 0x1},
    .read_buffer_size = 128,
    .battery_range = {0x00, 0x04}
};

const device_identifier *all_headphone_models[HEADPHONE_COUNT] = {
    &arctis_pro_wireless,
    &arctis_7_2017,
    &arctis_7_2019,
    &arctis_pro_2019,
    &arctis_pro_gamedac,
    &arctis_9,
    &arctis_1_wireless,
    &arctis_1_xbox,
    &arctis_7x,
    &arctis_7_plus,
    &arctis_7p_plus,
    &arctis_7x_plus,
    &arctis_7_destiny_plus,
    &arctis_nova_7,
    &arctis_nova_7x,
    &arctis_nova_7x_v2,
    &arctis_nova_7p,
    &arctis_nova_7_diablo_iv,
    &arctis_nova_5,
    &arctis_nova_5x
};

const size_t all_headphone_models_count = HEADPHONE_COUNT;