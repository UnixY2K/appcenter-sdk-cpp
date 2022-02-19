
#################################################################
# Shared configuration between the implementation and the API
#################################################################

appcenter_sdk_api_incl = include_directories('include')
appcenter_sdk_private_incl = include_directories('private')
appcenter_sdk_shared_incl = [
    appcenter_sdk_api_incl,
    appcenter_sdk_private_incl,
]
# there is no sense to compile shared sources
# appcenter_sdk_shared_src = []
# at the moment we don´t need shared arguments
# appcenter_sdk_shared_args = []
# all non public libraries should be wrapped in the implementation
# appcenter_sdk_shared_libs = []
appcenter_sdk_shared_deps = [
    cpp_libuuid_dep,
]

#################################################################
# SDK Implementation configuration
#################################################################

appcenter_sdk_core_incl = []
appcenter_sdk_core_srcs = [
    # SDK Implementation sources
    'src/sdk/core/logger.cpp',
    'src/sdk/core/platform.cpp',
    'src/sdk/ingestion/models/log.cpp',
    'src/sdk/ingestion/device.cpp',
    'src/sdk/util/Date.cpp',
    'src/sdk/appcenter.cpp',
]
appcenter_sdk_core_args = [
    '-DAPPCENTER_SDK_VERSION="' + appcenter_sdk_version + '"',
]
appcenter_sdk_core_link = []
appcenter_sdk_core_deps = [
    thread_dep,
    hinnant_date_dep,
    fmt_dep
]

## add shared configuration to the SDK implementation
appcenter_sdk_core_incl += appcenter_sdk_shared_incl
# appcenter_sdk_core_src += appcenter_sdk_shared_src
# appcenter_sdk_core_args += appcenter_sdk_shared_args
# appcenter_sdk_core_libs += appcenter_sdk_shared_libs
appcenter_sdk_core_deps += appcenter_sdk_shared_deps

## add platform specific configuration to the SDK implementation

subdir('impl')

## utilities
appcenter_sdk_utilities = []

appcenter_sdk_core_srcs += appcenter_sdk_utilities

## add implementation
appcenter_sdk_core_srcs += appcenter_sdk_impl_srcs
appcenter_sdk_core_args += appcenter_sdk_impl_args
appcenter_sdk_core_link += appcenter_sdk_impl_link
appcenter_sdk_core_deps += appcenter_sdk_impl_deps

### SDK Implementation library
appcenter_sdk_core_lib = static_library('appcenter-sdk-core',
                            appcenter_sdk_core_srcs,
                            include_directories : appcenter_sdk_core_incl,
                            cpp_args: appcenter_sdk_core_args,
                            dependencies : appcenter_sdk_core_deps)

#################################################################
# SDK API configuration
#################################################################
appcenter_sdk_incl = []
appcenter_sdk_srcs = [   
    # API sources
    'src/appcenter/api/memory.cpp',
    # SDK bindings
    'src/appcenter/api/bindings.cpp',
]
appcenter_sdk_args = []
appcenter_sdk_link = [ appcenter_sdk_core_lib ]
appcenter_sdk_deps = []
appcenter_sdk_args = []

## add shared configuration to the SDK API
appcenter_sdk_incl += appcenter_sdk_shared_incl
# appcenter_sdk_src += appcenter_sdk_shared_src
# appcenter_sdk_args += appcenter_sdk_shared_args
# appcenter_sdk_libs += appcenter_sdk_shared_libs
appcenter_sdk_deps += appcenter_sdk_shared_deps

appcenter_sdk_lib = library('appcenter-sdk',
                        appcenter_sdk_srcs,
                        include_directories : appcenter_sdk_incl,
                        link_with : appcenter_sdk_link,
                        cpp_args: appcenter_sdk_args,
                        dependencies : appcenter_sdk_deps)
                        

appcenter_sdk_dep = declare_dependency(
    link_with: appcenter_sdk_lib,
    include_directories: appcenter_sdk_api_incl
)
