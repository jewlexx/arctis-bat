project('arctis-devices', 'c', version: '0.1.1')

drivers_incdir = include_directories('include')

drivers = shared_library(
  'arctis-devices',
  'src/devices.c',
  'src/devices/arctis_pro_wireless.c',
  'src/devices/arctis_7_2017.c',
  'src/devices/arctis_7_2019.c',
  'src/devices/arctis_pro_2019.c',
  'src/devices/arctis_pro_gamedac.c',
  'src/devices/arctis_9.c',
  'src/devices/arctis_1_wireless.c',
  'src/devices/arctis_1_xbox.c',
  'src/devices/arctis_7x.c',
  'src/devices/arctis_7_plus.c',
  'src/devices/arctis_7p_plus.c',
  'src/devices/arctis_7x_plus.c',
  'src/devices/arctis_7_destiny_plus.c',
  'src/devices/arctis_nova_7.c',
  'src/devices/arctis_nova_7x.c',
  'src/devices/arctis_nova_7x_v2.c',
  'src/devices/arctis_nova_7p.c',
  'src/devices/arctis_nova_7_diablo_iv.c',
  'src/devices/arctis_nova_5.c',
  'src/devices/arctis_nova_5x.c',
  include_directories: drivers_incdir,
  install: true,
  c_args: [
    '-Wall',
    '-Wextra',
    '-Wpedantic',
  ],
)

install_headers(
  'include/devices.h',
  'include/identifier.h',
  'include/devices/arctis_pro_wireless.h',
  'include/devices/arctis_7_2017.h',
  'include/devices/arctis_7_2019.h',
  'include/devices/arctis_pro_2019.h',
  'include/devices/arctis_pro_gamedac.h',
  'include/devices/arctis_9.h',
  'include/devices/arctis_1_wireless.h',
  'include/devices/arctis_1_xbox.h',
  'include/devices/arctis_7x.h',
  'include/devices/arctis_7_plus.h',
  'include/devices/arctis_7p_plus.h',
  'include/devices/arctis_7x_plus.h',
  'include/devices/arctis_7_destiny_plus.h',
  'include/devices/arctis_nova_7.h',
  'include/devices/arctis_nova_7x.h',
  'include/devices/arctis_nova_7x_v2.h',
  'include/devices/arctis_nova_7p.h',
  'include/devices/arctis_nova_7_diablo_iv.h',
  'include/devices/arctis_nova_5.h',
  'include/devices/arctis_nova_5x.h',
  subdir: 'arctis-devices',
)

drivers_dep = declare_dependency(link_with: drivers, include_directories: drivers_incdir)