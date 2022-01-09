fs = import('fs')

appcenter_sdk_impl_sources = []
appcenter_sdk_impl_args    = []
appcenter_sdk_impl_link    = []
appcenter_sdk_impl_deps    = []

impl_dir = host_machine.system()

appcenter_sdk_impl_src_dir = 'impl' / impl_dir

if fs.is_dir(impl_dir)
    message('Using ' + impl_dir + ' implementation: ')
    subdir(impl_dir)
else
    message('platform' + impl_dir + 'not supported, aborting')
    assert(false)
endif
