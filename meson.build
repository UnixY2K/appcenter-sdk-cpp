project(
    'appcenter-sdk', 'cpp',
    default_options: ['cpp_std=c++17'],
    version: '1.0.0 v2021',
    license: 'BSD-3'
)
version = '1.0.0 v2022'

catch2_dep = dependency(
                'catch2',
                fallback: ['catch2', 'catch2_dep']
)


cpp_libuuid_dep = dependency(
                'cpp_libuuid',
                fallback: ['cpp_libuuid', 'cpp_libuuid_dep']
)

restclient_cpp_dep = dependency(
                'restclient_cpp',
                fallback: ['restclient-cpp', 'restclient_cpp_dep']
)

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
