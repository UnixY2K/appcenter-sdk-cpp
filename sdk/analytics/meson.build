#################################################################
# Shared configuration between the implementation and the API
#################################################################

## Public and private includes
appcenter_analytics_api_incl = include_directories('include')
appcenter_analytics_private_incl = include_directories('private')

## Shared configurations

appcenter_analytics_shared_incl = [
    appcenter_analytics_api_incl,
    appcenter_analytics_private_incl,
    appcenter_sdk_shared_incl,
]
# there is no sense to compile shared sources
# appcenter_analytics_shared_src = []
# at the moment we don´t need shared arguments
# appcenter_analytics_shared_args = []
# all non public libraries should be wrapped in the implementation
# appcenter_analytics_shared_libs = []
appcenter_analytics_shared_deps = [
    appcenter_sdk_shared_deps,
]

#################################################################
# Analytics Implementation configuration
#################################################################

appcenter_analytics_core_incl = []
appcenter_analytics_core_srcs = [
    'src/analytics/analytics.cpp',
]
appcenter_analytics_core_args = []
appcenter_analytics_core_link = [appcenter_sdk_core_lib]
appcenter_analytics_core_deps = []

## add shared configuration to the Analytics implementation
appcenter_analytics_core_incl += appcenter_analytics_shared_incl
# appcenter_analytics_core_src  += appcenter_analytics_shared_src
# appcenter_analytics_core_args += appcenter_analytics_shared_args
# appcenter_analytics_core_libs += appcenter_analytics_shared_libs
appcenter_analytics_core_deps += appcenter_analytics_shared_deps

### Analytics Implementation library
appcenter_analytics_core_lib = static_library('appcenter-analytics-core',
                                    appcenter_analytics_core_srcs,
                                    include_directories : appcenter_analytics_core_incl,
                                    link_with : appcenter_analytics_core_link,
                                    cpp_args: appcenter_analytics_core_args,
                                    dependencies : appcenter_analytics_core_deps)

#################################################################
# Analytics API configuration
#################################################################
appcenter_analytics_incl = []
appcenter_analytics_srcs = [
    'src/analytics/api/analytics-api.cpp',
]
appcenter_analytics_link = [
    appcenter_analytics_core_lib,
]
appcenter_analytics_deps = []
appcenter_analytics_args = []

## add shared configuration to the Analytics API
appcenter_analytics_incl += appcenter_analytics_shared_incl
# appcenter_analytics_src  += appcenter_analytics_shared_src
# appcenter_analytics_args += appcenter_analytics_shared_args
# appcenter_analytics_libs += appcenter_analytics_shared_libs
appcenter_analytics_deps += appcenter_analytics_shared_deps

appcenter_analytics_lib = library('appcenter-analytics',
                        appcenter_analytics_srcs,
                        include_directories : appcenter_analytics_incl,
                        link_with : appcenter_analytics_link,
                        cpp_args: appcenter_analytics_args,
                        dependencies : appcenter_analytics_deps)
                        

appcenter_analytics_dep = declare_dependency(
    link_with: appcenter_analytics_lib,
    include_directories: appcenter_analytics_api_incl
)
