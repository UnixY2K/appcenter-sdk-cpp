appcenter_demo_inc = include_directories('include')

appcenter_demo_sources = [
    'src/source.cpp',
    'src/example.cpp',
]
appcenter_demo_args = []
appcenter_demo_link = [
    appcenter_sdk_lib,
]
appcenter_demo_deps = [
    appcenter_sdk_dep
]


## demo executable
appcenter_demo_exe = executable('appcenter_demo',
                            appcenter_demo_sources,
                            include_directories: appcenter_demo_inc,
                            cpp_args: appcenter_demo_args,
                            dependencies: appcenter_demo_deps,
                            link_with: appcenter_demo_link)