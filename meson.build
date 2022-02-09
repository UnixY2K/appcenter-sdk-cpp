project(
    'appcenter-sdk', 'cpp',
    default_options: ['cpp_std=c++17'],
    version: '0.0.1 v2022',
    license: 'BSD-3'
)

appcenter_sdk_ver = meson.project_version()
appcenter_sdk_version = appcenter_sdk_ver

# catch2 for unit tests
catch2_dep = dependency(
                'catch2',
                fallback: ['catch2', 'catch2_dep']
)

# libuuid for UUID generation
cpp_libuuid_dep = dependency(
                'cpp_libuuid',
                fallback: ['cpp_libuuid', 'cpp_libuuid_dep']
)

# nlohmann json for serialization in the SDK
nlohmann_json_dep = dependency(
                'nlohmann_json',
                fallback: ['nlohmann_json', 'nlohmann_json_dep']
)

# resclient-cpp for the SDK ingestion
restclient_cpp_dep = dependency(
                'restclient_cpp',
                fallback: ['restclient-cpp', 'restclient_cpp_dep']
)

thread_dep = dependency('threads')

subdir('sdk')
if get_option('build_tests')
    subdir('test')
else
    message('Skipping tests')
endif
if get_option('build_samples')
    subdir('samples')
else
    message('Skipping samples')
endif
