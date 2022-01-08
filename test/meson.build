test_sources = [
    'source.cpp',
]

test_dependencies = [
    catch2_dep,
    appcenter_sdk_dep
]

testexe = executable('testexe', test_sources,
                     #include_directories : appcenter_sdk_inc,
                     #link_with : appcenter_sdk_lib,
                     dependencies: test_dependencies)
test('appcenter sdk test', testexe)