import fs from "fs";
import { all_devices } from "./devices.js";

function stringify_hex_array(arr, pad = 2) {
  return arr.map((b) => `0x${b.toString(16).padStart(pad, "0")}`).join(", ");
}

const devices = all_devices.map((device) => {
  const c_instantiation = `const device_identifier ${device.name
    .replace(/\s+/g, "_")
    .toLowerCase()} = {
    .name = "${device.name}",
    .product_id = 0x${device.product_id.toString(16).padStart(4, "0")},
    .write_bytes = {${stringify_hex_array(device.write_bytes)}},
    .interface_number = ${device.interface_number},
    .battery_percentage_index = ${device.battery_percentage_index},
    .charging_status_index = ${device.charging_status_index},
    .connected_status_index = ${device.connected_status_index},
    .usage_page_and_id = {${stringify_hex_array(device.usage_page_and_id)}},
    .read_buffer_size = ${device.read_buffer_size},
    .battery_range = {${stringify_hex_array(device.battery_range)}}
};`;

  const ident = device.name.replace(/\s+/g, "_").toLowerCase();

  return {
    name: ident,
    c_code: `#include "devices/${ident}.h"\n\n${c_instantiation}\n`,
    h_code: `#pragma once\n#include "../devices.h"\nextern const device_identifier ${ident};\n`,
    meson_file: `src/devices/${ident}.c`,
    include_header: `#include "include/devices/${ident}.h"`,
  };
});

console.log(devices);

for (const device of devices) {
  fs.writeFileSync(
    `subprojects/drivers/src/devices/${device.name}.c`,
    device.c_code
  );
  console.log(`'${device.meson_file}',`);
}

for (const device of devices) {
  fs.writeFileSync(
    `subprojects/drivers/include/devices/${device.name}.h`,
    device.h_code
  );
  console.log(`${device.include_header}`);
}
