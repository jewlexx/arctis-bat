project('arctis-bat', 'c', version: '0.1.0')

hidapi_dep = dependency('hidapi-hidraw')

lib = static_library(
  'device-code',
  'src/device.c',
  'src/drivers.c',
  'src/drivers/arctis_pro_wireless.c',
  'src/drivers/arctis_7_2017.c',
  'src/drivers/arctis_7_2019.c',
  'src/drivers/arctis_pro_2019.c',
  'src/drivers/arctis_pro_gamedac.c',
  'src/drivers/arctis_9.c',
  'src/drivers/arctis_1_wireless.c',
  'src/drivers/arctis_1_xbox.c',
  'src/drivers/arctis_7x.c',
  'src/drivers/arctis_7_plus.c',
  'src/drivers/arctis_7p_plus.c',
  'src/drivers/arctis_7x_plus.c',
  'src/drivers/arctis_7_destiny_plus.c',
  'src/drivers/arctis_nova_7.c',
  'src/drivers/arctis_nova_7x.c',
  'src/drivers/arctis_nova_7x_v2.c',
  'src/drivers/arctis_nova_7p.c',
  'src/drivers/arctis_nova_7_diablo_iv.c',
  'src/drivers/arctis_nova_5.c',
  'src/drivers/arctis_nova_5x.c'
)

incdir = include_directories('include')

executable(
  'arctisbat',
  'src/main.c',
  dependencies: [hidapi_dep],
  include_directories: incdir,
  link_with: lib,
  install: true,
)
