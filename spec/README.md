# App Center Specification

This specification contains a description about the requirements to make a App Center SDK,
in this case for C++ code most of this documentation is based on the implementation/design
of the SDK present in C#/Xamarin and Java/Android Implementation, however the code is
written from scratch and may be some differences from their counterparts mainly to
language and target platform differences, so do not expect it to be an 1-1 equivalent even
on some API methods.

## App Center Core

At the Core App Center SDK needs the following components, that will be discused on [core spec](core/core.md).

- Startup method.
- Service utilities and interfaces for all the sub-services.
- Configuration and logging.
- Network Services and API Ingestion.
- Library exports/API for the programs which use this SDK.
- App Secret handler.

## App Center Core/Internals

App Center SDK may/will need to expose some internal utilites to its internal components
An example of this services are the following:

- Util methods like UUID generation. [libuuid](https://github.com/ninjaoflight/cpp-libuuid)
- A Date library. [hinnant-date](https://github.com/HowardHinnant/date)
- A JSON parsing library. [nlohmann-json](https://json.nlohmann.me/)
- HTTP request library. [restclient-cpp(fork)](https://github.com/ninjaoflight/restclient-cpp)
- A internal Logger and error mechanism.
- Platform Specific information collector.
- Exception handling/ error reporting mechanism.
- SQLite database library. [sqlitecpp (fork)](https://github.com/ninjaoflight/SQLiteCpp)
- Test Cloud checker.
- SDK Information.
- App Secret provider. (internal, app secrets implemented by user)
- Unit testing library [catch2](https://github.com/catchorg/Catch2)
