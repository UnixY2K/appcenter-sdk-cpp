# App Center web requests

App Center SDK does the request to the App Center web API when it is allowed to do so.

## Request format

the basic request format is the following:

- Method: POST
- URL: https://in.appcenter.ms
- API Path: /logs?api-version=1.0.0
- Content-Type: application/json
- Headers:
  - App-Secret: `App Secret`
  - Install-ID: `Install ID`
- Body: an object with the request data, it contains a `"logs"` object which is an array
 ```json
    {
        "logs": [
            {
                "type": "<type>",
                "timestamp": "<ISO 8601 timestamp>",
                "sid": "<sid>",
                "device": {
                    "sdkName": "<sdkName>",
                    "sdkVersion": "<sdkVersion>",
                    "model": "[model]",
                    "oemName": "[oemName]",
                    "osName": "<osName>",
                    "osVersion": "<osVersion>",
                    "osBuild": "[osBuild]",
                    "osApiLevel": "[osApiLevel] (integer)",
                    "locale": "<locale>",
                    "timeZoneOffset": "<timeZoneOffset> (integer)",
                    "screenSize": "[screenSize]",
                    "appVersion": "[appVersion]",
                    "carrierName": "[carrierName] (only mobile)",
                    "carrierCountry": "[carrierCountry] (only mobile)",
                    "appBuild": "<appBuild>",
                    "appNamespace": "[appNamespace]"
                }
            }
        ]
    }
 ```

 > there is another flags like `jailbreak` or live update that can be sent but in this
SDK implementation they do not have sense, if you require those flags you can use interop,
with the SDK that haves that feature.

> all the data inside "device" is provided by the SDK Ingestion engine, however some
values can/(need to) be overwritten using the API

> the values sorrounding by `[]` are optional, but the values inside `<>` are required,
as for the `()` is for specify an exception like the integer values or the only mobile

## Request types format

> the additional data is sent after the `device` object, it changes depending on the type

> the SDK can send multiple `"log objects"` in the same request, this can be used for
example when sending events.

the list of the supported `types` by this SDK are:
- `"startService"`: when the SDK starts a service, sends the `service` array with the
  services started, example:
  ```json
    "services": [
        "Analytics",
        "Crashes",
        "Distribute"
    ]
  ```
- `"startSession"` when the SDK session starts, does not send any additional data
- `"event"` for any event data created using the SDK itself, it sends the following data:
  - `"name"`: the name of the event
  - `"id"`: an UUID for this event
  - `"typedProperties"` (optional): an array with a typedProperty object for each property,
  the property has the following structure:
    - `"type"`: the type of the property, are the the following
      - boolean: `true`, `false`
      - DateTime: `"ISO 8601 timestamp"`
      - Double: `3.7`
      - Long: `3`
      - String: `"hello"`
    - `"name"`: the name of the property
    - `"value"`: the value of the property
  - example of the data sent:
    ```json
        "name": "Color event",
        "id": "8ded3245-a056-44b4-a1c7-07f3617ebbfa",
        "typedProperties": [
            {
            "type": "string",
            "name": "Color",
            "value": "Red"
            }
        ]
    ```

## Request response

the App Center web service will return a response with the following format:

- Status: HTTP status code
- Content-Type: application/json
- body: the response body with additional information
    - `"status"`: the result of the request, it is a String with the result/error,
    useful for debugging
    - `"validDiagnosticsIDS"`: an array with the valid diagnostic ids, unused.
    - `"validDiagnosticsIDs"`: an array with the throttled diagnostic ids, unused.
    - `"correlationId"`: the correlation id of the request, unused.

example of the response

```json
        {
        "status": "Success",
        "validDiagnosticsIds": [],
        "throttledDiagnosticsIds": [],
        "correlationId": "ddd965a0-0713-4150-bf33-7bd5e3245695"
    }
```

> the correlation ID is a GUID generated for each web request received by the App Center
  web services, for internal use and Microsoft support team.

## Request crashes

the crashes report feature will be discused on a later section.
