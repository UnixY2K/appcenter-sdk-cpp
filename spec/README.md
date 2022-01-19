# App Center Specification

This specification contains a description about the requirements to make a App Center SDK,
in this case for C++ code most of this documentation is based on the implementation/design
of the SDK present in C#/Xamarin and Java/Android Implementation, however the code is
written from scratch and may be some differences from their counterparts mainly to
language and target platform differences, so do not expect it to be an 1-1 equivalent even
on some API methods.

## App Center Core

At the Core App Center SDK needs the following components, that will be discused on [core spec](core.md).

- Startup method.
- Service utilities and interfaces for all the sub-services.
- Configuration and logging.
- Network Services and API Ingestion.
- Library exports/API for the programs which use this SDK.
- App Secret handler.

## App Center Core/Internals

App Center SDK may/will need to expose some internal utilites to its internal components
An example of this services are the following:

- Util methods like UUID generation.
- A Date library.
- A JSon parsing library.
- Some kind of HTTP request library.
- A internal Logger and error mechanism.
- Platform Specific information collector.
- Exception handling/ error reporting mechanism.
- SQLite database library.
- Test Cloud checker.
- SDK Information.
- App Secret provider.
