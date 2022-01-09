impl_sources = [
    'src/linuxImpl.cpp',
    'src/util/uuid.cpp',
]

# libuuid for Linux
libuuid = dependency('uuid', required: true)
if libuuid.found()
    message('found libuuid')
endif

appcenter_sdk_impl_deps += libuuid

foreach src : impl_sources
    appcenter_sdk_impl_sources += appcenter_sdk_impl_src_dir + '/' + src
endforeach
