#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum ChargingStatus {
  Charging = 1,
  Discharging = 3,
  Disconnected = 0,
} ChargingStatus;

typedef struct DeviceInfo {
  const void *inner;
} DeviceInfo;

typedef struct DeviceStatus {
  float battery;
  ChargingStatus status;
} DeviceStatus;

struct DeviceInfo initialize_device(void);

void get_status(const void *device_info, struct DeviceStatus *status);
