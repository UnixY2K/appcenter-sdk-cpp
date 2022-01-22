# App Center Core Logger

App Center spec requires some logger services for itself and also for capturing logs from
the application that uses the SDK.

## App Center Logger

App Center SDK has a logger library that is used by the SDK itself, however, you can use
any logger library that you want, as this is used only for capturing logs from the SDK,
though you could link your logger library to App Center in order to get the logs sent to
App Center.

### App Center Logger levels

App Center SDK has a set of log levels that are used to control the amount of logs output
here is the list of log levels:

| Level   | Description                                         |
| ------- | --------------------------------------------------- |
| Verbose | SDK emmits all possible level of logs               |
| Debug   | SDK emmits debug, info, warn, error and assert logs |
| Info    | SDK emmits warn, error, and assert logs             |
| Warn    | SDK emmits error and assert logs                    |
| Error   | SDK emmits error and assert logs                    |
| Assert  | Only assert logs are emmited by the SDK             |
| None    | No logs are emmited by the SDK                      |

### App Center Logger methods

App Center Logger have the following list of required methods:

> all the log methods have a tag and message parameter

| Method      | Description                         |
| ----------- | ----------------------------------- |
| getLogger   | Get the internal logger used        |
| setLogger   | Set the internal logger to use      |
| setLogLevel | Set the log level used by the SDK   |
| getLogLevel | Get the log level used by the SDK   |
| getLogTag   | Get the Log Tag for the current SDK |
| setLogTag   | Set the Log Tag for the current SDK |
| verbose     | Log verbose message                 |
| debug       | Log debug message                   |
| info        | Log info message                    |
| warn        | Log warn message                    |
| error       | Log error message                   |
| assert      | Log assert message                  |
