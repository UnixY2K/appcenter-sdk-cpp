# App Center Core

App Center SDK needs a list of core components, do not confuse it with internals,
utils or another libraries needed for the implementation

## SDK Information

the core services need at least provide basic information about the App Center information
on the device, this is the following list of information that the SDK needs as required

> some of the parameters can/needs to be specified by the application as this SDK
does not make hard assumptions about the target platform/device so some data
is not generally available like OsName or app version

### Ingestion Data

---

**Required Data** for Ingestion

---

| Name           | Type   | example       | Description                          |
| -------------- | ------ | ------------- | ------------------------------------ |
| sdkName        | String | appcenter.ios | SDK and platform                     |
| sdkVersion     | String | 1.2.0         | Semver format                        |
| osName         | String | iOS           | Os name                              |
| osVersion      | String | 9.3.0         | Os Version                           |
| locale         | String | en_US         | System ISO country and language code |
| timeZoneOffset | Int    |               | UTC system offset in minutes         |
| appVersion     | String | 1.2.0         | Application Version name             |
| appBuild       | String | 42            | Application Build Number             |

> The time zone offset includes daylight savings time.
> on Linux the os name is the Distro Name and the version is the kernel version/name

---

## Core Logger

- Custom properties
- Test cloud

- Startup method.
- Service utilities and interfaces for all the sub-services.
- Configuration and logging.
- Network Services and API Ingestion.
- Library exports/API for the programs which use this SDK.
- App Secret handler.
