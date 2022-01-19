# SDK Ingestion data

the core services need at least provide basic information about the App Center information
of the device, this is the following list of information that the SDK needs as required

> some of the parameters can/needs to be specified by the application as this SDK
does not make hard assumptions about the target platform/device so some data
is not generally aivailable like OsName or app version

## Headers request data

| Name           | Type   | example       | Description                          |
| -------------- | ------ | ------------- | ------------------------------------ |
| App-Secret     | String |               | App Secret unique key for the app    |
| Install-ID     | String |               | UUID install ID to differentiate it  |

## Ingestion Data

### **Required Data** for Ingestion


| Name           | example       | Description                          |
| -------------- | ------------- | ------------------------------------ |
| sdkName        | appcenter.ios | SDK and platform                     |
| sdkVersion     | 1.2.0         | Semver format                        |
| osName         | iOS           | Os name                              |
| osVersion      | 9.3.0         | Os Version                           |
| locale         | en_US         | System ISO country and language code |
| timeZoneOffset |               | UTC system offset in minutes         |
| appVersion     | 1.2.0         | Application Version name             |
| appBuild       | 42            | Application Build Number             |

> The time zone offset includes daylight savings time.
> on Linux the os name is the Distro Name and the version is the kernel version/name

### **Non required/optional data** for Ingestion

| Name                    | example              | Description                      |
| ----------------------- | -------------------- | -------------------------------- |
| timestamp               | 2017-03-13T18:05:42Z | Log timestamp                    |
| sid                     |                      | Session ID                       |
| userId                  |                      | Required to track users with logs|
| wrapperSdkVersion       | Xamarin.Android      | the version of the wrapper SDK   |
| wrapperSdkName          | appcenter.xamarin    | SDK and wrapper platform         |
| model                   | iPad2,3              | The device model                 |
| oemName                 | HTC                  | the device manufacturer          |
| osBuild                 | LMY47X               | OS build code                    |
| osApiLevel              | 15                   | API level when applicable        |
| screenSize              | 1920x1080            | Screen resolution in pixels      |
| appVersion              | 1.1.42               | version of the application       |
| appNamespace            | com.company.app      | App package identifier           |

### **Specific Mobile Data** for Ingestion

| Name                    | example              | Description                      |
| ----------------------- | -------------------- | -------------------------------- |
| carrierName             | Verizon              | Carrier name if applicable       |
| carrierCountry          |                      | Country of the cell provider     |

### **Specific Live Update Data** for Ingestion

| Name                    | example              | Description                      |
| ----------------------- | -------------------- | -------------------------------- |
| liveUpdateReleaseLabel  |                      | label to identify the release    |
| liveUpdateDeploymentKey | Production           | the identifier of the enviroment |
| liveUpdatePackageHash   |                      | hash of all files of the app     |
| wrapperRuntimeVersion   |                      | version of the wrapper framework |

### **Miscellaneous Data** for Ingestion

| Name                    | example              | Description                      |
| ----------------------- | -------------------- | -------------------------------- |
| jailbreak               |                      | a flag that indicates jailbreak  |