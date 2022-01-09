test_sources = [
    'appcenter/source.cpp',
    'appcenter/util/UUIDtest.cpp',
]

test_dependencies = [
    catch2_dep,
    appcenter_sdk_dep,
]

testexe = executable('testexe', test_sources,
                     #include_directories : appcenter_sdk_inc,
                     link_with : appcenter_sdk_test_lib,
                     dependencies: test_dependencies)

test_args = []

if get_option('test_report')
    message('using JUnit XML report output')
    test_args += [
        '--reporter xml'
    ]
endif


test('appcenter sdk test', testexe, args: test_args)