project('arctis-bat', 'c', version: '0.1.0')

hidapi_dep = dependency('hidapi-hidraw')

lib = static_library('device-code', 'src/device.c', 'src/all_devices.c')

incdir = include_directories('include')

executable(
  'arctisbat',
  'src/main.c',
  dependencies: [hidapi_dep],
  include_directories: incdir,
  link_with: lib,
  install: true,
)
