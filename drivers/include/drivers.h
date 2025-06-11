#pragma once

#include "drivers/include/drivers/arctis_pro_wireless.h"
#include "drivers/include/drivers/arctis_7_2017.h"
#include "drivers/include/drivers/arctis_7_2019.h"
#include "drivers/include/drivers/arctis_pro_2019.h"
#include "drivers/include/drivers/arctis_pro_gamedac.h"
#include "drivers/include/drivers/arctis_9.h"
#include "drivers/include/drivers/arctis_1_wireless.h"
#include "drivers/include/drivers/arctis_1_xbox.h"
#include "drivers/include/drivers/arctis_7x.h"
#include "drivers/include/drivers/arctis_7_plus.h"
#include "drivers/include/drivers/arctis_7p_plus.h"
#include "drivers/include/drivers/arctis_7x_plus.h"
#include "drivers/include/drivers/arctis_7_destiny_plus.h"
#include "drivers/include/drivers/arctis_nova_7.h"
#include "drivers/include/drivers/arctis_nova_7x.h"
#include "drivers/include/drivers/arctis_nova_7x_v2.h"
#include "drivers/include/drivers/arctis_nova_7p.h"
#include "drivers/include/drivers/arctis_nova_7_diablo_iv.h"
#include "drivers/include/drivers/arctis_nova_5.h"
#include "drivers/include/drivers/arctis_nova_5x.h"

#define HEADPHONE_COUNT 20

// Steelseries Vendor ID
#define VENDOR_ID 0x1038

typedef struct {
    const char *name;
    uint16_t product_id;
    uint8_t write_bytes[2];
    int32_t interface_number;
    int battery_percentage_index;
    int charging_status_index;
    int connected_status_index;
    uint16_t usage_page_and_id[2];
    int read_buffer_size;
    uint16_t battery_range[2];
} device_identifier;

extern const device_identifier *all_headphone_models[HEADPHONE_COUNT];

extern const size_t all_headphone_models_count;
