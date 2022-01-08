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

# example dependency
#terminalpp_dep = dependency(
#                    'terminalpp',
#                    fallback: ['terminalpp', 'terminalpp_dep']
#)

subdir('sdk')
subdir('test')
subdir('samples')
