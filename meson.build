project('arctis-bat', 'c')

hidapi_dep = dependency('hidapi-libusb')

lib = static_library('device-code', 'device.c')

executable(
  'arctisbat',
  'main.c',
  dependencies: [hidapi_dep],
  link_with: lib,
  # install: true,
  # install_dir: get_option('libexecdir'),
)
