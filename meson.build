project('arctis-bat', 'c', version: '0.1.0')

hidapi_dep = dependency('hidapi-hidraw')

lib = static_library('device-code', 'device.c')

executable(
  'arctisbat',
  'main.c',
  dependencies: [hidapi_dep],
  link_with: lib,
  install: true,
)
