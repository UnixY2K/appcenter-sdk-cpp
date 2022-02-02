appcenter_sample_args = []
if get_option('appcenter_sample_app_secret') != ''
    message('[APPCENTER-SDK][SAMPLES]: adding sample app secret to demos')
    appcenter_sample_args += [
    '-DAPPCENTER_SAMPLE_APP_SECRET="'+get_option('appcenter_sample_app_secret')+'"',
    ]
endif


# just comment the sample app that you don´t want to test
## add app center app secret to arguments
subdir('demo')