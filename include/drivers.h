#pragma once

#include "device.h"
#include "drivers/arctis_pro_wireless.h"
#include "drivers/arctis_7_2017.h"
#include "drivers/arctis_7_2019.h"
#include "drivers/arctis_pro_2019.h"
#include "drivers/arctis_pro_gamedac.h"
#include "drivers/arctis_9.h"
#include "drivers/arctis_1_wireless.h"
#include "drivers/arctis_1_xbox.h"
#include "drivers/arctis_7x.h"
#include "drivers/arctis_7_plus.h"
#include "drivers/arctis_7p_plus.h"
#include "drivers/arctis_7x_plus.h"
#include "drivers/arctis_7_destiny_plus.h"
#include "drivers/arctis_nova_7.h"
#include "drivers/arctis_nova_7x.h"
#include "drivers/arctis_nova_7x_v2.h"
#include "drivers/arctis_nova_7p.h"
#include "drivers/arctis_nova_7_diablo_iv.h"
#include "drivers/arctis_nova_5.h"
#include "drivers/arctis_nova_5x.h"

#define HEADPHONE_COUNT 20

extern const device_identifier *all_headphone_models[HEADPHONE_COUNT];

extern const size_t all_headphone_models_count;
