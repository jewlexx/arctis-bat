#include <stdint.h>

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
