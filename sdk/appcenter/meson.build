appcenter_sdk_inc = include_directories('include')

appcenter_sdk_sources = [
    'src/appcenter.cpp',
    'src/appcenter-sdk.cpp',
]
appcenter_sdk_args = []
appcenter_sdk_link = []
appcenter_sdk_deps = []

subdir('impl')

# add implementation
appcenter_sdk_sources += appcenter_sdk_impl_sources
appcenter_sdk_args    += appcenter_sdk_impl_args
appcenter_sdk_link    += appcenter_sdk_impl_link
appcenter_sdk_deps    += appcenter_sdk_impl_deps

appcenter_sdk_lib = library('appcenter-sdk',
                        appcenter_sdk_sources,
                        include_directories : appcenter_sdk_inc,
                        cpp_args: appcenter_sdk_args,
                        dependencies : appcenter_sdk_deps)

appcenter_sdk_dep = declare_dependency(
    link_with: appcenter_sdk_lib,
    include_directories: appcenter_sdk_inc
)