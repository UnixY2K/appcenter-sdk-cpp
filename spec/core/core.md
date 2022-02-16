# App Center Core

App Center SDK needs a list of core components, do not confuse it with internals,
utils or another libraries needed for the implementation

## Ingestion Data

App Center SDK collects and send data to App Center, this data is processed by
the [Ingestion](ingestion.md) engine, this is the list of the Ingestion data that the SDK
process

## Requests format

App Center SDK sends requests to an specific endpoint, depending on the type of service,
it can use different endpoints, and body format, you can check more in [Requests](requests.md)

## Channels

A [channel](channel.md) is a way to control the output of the SDK and its services,
also it helps with their Logs(ingestion data) persistence, and their priority.

## Core Logger

App Center SDK [Logger](logger.md) library that is used by the SDK itself across all
its components, useful for capturing logs from the SDK.

- Startup method.
- Service utilities and interfaces for all the sub-services.
- Configuration.
- Network Services and API Ingestion.
- Library exports/API for the programs which use this SDK.
- App Secret handler.
