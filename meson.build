project('arctis-bat', 'c', version: '0.1.0')

hidapi_dep = dependency('hidapi-hidraw')

driversproj = subproject('drivers')
drivers_dep = driversproj.get_variable('drivers_dep')

executable_incdir = include_directories('include')

executable(
  'arctisbat',
  'src/main.c',
  'src/device.c',
  dependencies: [hidapi_dep, drivers_dep],
  c_args: ['-Wall', '-Wextra', '-Wpedantic'],
  include_directories: executable_incdir,
  install: true,
)
