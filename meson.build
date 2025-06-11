project('arctis-bat', 'c', version: '0.1.0')

hidapi_dep = dependency('hidapi-hidraw')

drivers_incdir = include_directories('drivers/include')

lib = static_library(
  'arctis-devices',
  'drivers/src/drivers.c',
  'drivers/src/drivers/arctis_pro_wireless.c',
  'drivers/src/drivers/arctis_7_2017.c',
  'drivers/src/drivers/arctis_7_2019.c',
  'drivers/src/drivers/arctis_pro_2019.c',
  'drivers/src/drivers/arctis_pro_gamedac.c',
  'drivers/src/drivers/arctis_9.c',
  'drivers/src/drivers/arctis_1_wireless.c',
  'drivers/src/drivers/arctis_1_xbox.c',
  'drivers/src/drivers/arctis_7x.c',
  'drivers/src/drivers/arctis_7_plus.c',
  'drivers/src/drivers/arctis_7p_plus.c',
  'drivers/src/drivers/arctis_7x_plus.c',
  'drivers/src/drivers/arctis_7_destiny_plus.c',
  'drivers/src/drivers/arctis_nova_7.c',
  'drivers/src/drivers/arctis_nova_7x.c',
  'drivers/src/drivers/arctis_nova_7x_v2.c',
  'drivers/src/drivers/arctis_nova_7p.c',
  'drivers/src/drivers/arctis_nova_7_diablo_iv.c',
  'drivers/src/drivers/arctis_nova_5.c',
  'drivers/src/drivers/arctis_nova_5x.c',
  include_directories: drivers_incdir,
)

incdir = include_directories('include')

executable(
  'arctisbat',
  'src/main.c',
  'src/device.c',
  dependencies: [hidapi_dep],
  include_directories: incdir,
  link_with: lib,
  install: true,
)
