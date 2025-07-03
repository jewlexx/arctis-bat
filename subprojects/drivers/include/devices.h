#pragma once

#include <stddef.h>

#include "identifier.h"

#define HEADPHONE_COUNT 20

// Steelseries Vendor ID
#define VENDOR_ID 0x1038

extern const device_identifier *all_headphone_models[HEADPHONE_COUNT];

extern const size_t all_headphone_models_count;
