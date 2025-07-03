project('arctis-bat', 'c', version: '0.2.1')

hidapi_dep = dependency('hidapi-hidraw')

driversproj = subproject('drivers')
drivers_dep = driversproj.get_variable('drivers_dep')

executable_incdir = include_directories('include')

native_cpu = get_option('cpu_native')

if native_cpu
  c_args = ['-march=native', '-mtune=native']
else
  c_args = []
endif

c_args += ['-Wall', '-Wextra', '-Wpedantic']

executable(
  'arctis-bat',
  'src/main.c',
  'src/device.c',
  dependencies: [hidapi_dep, drivers_dep],
  c_args: c_args,
  include_directories: executable_incdir,
  install: true,
)