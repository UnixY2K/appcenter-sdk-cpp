# App Center Core - Channel

App Center SDK channel is used to control the multiple services output,
for example you can set a storage limit for the channel, enable/disable and others,
it also exposes a listener interface for design purposes.

## Channel flags

The flags are used to control the channel behavior and priority,

| name              | value |
| ----------------  | ----- |
| NORMAL            | 0x01  |
| CRITICAL          | 0x02  |
| DEFAULT           | 0x01  |
| PERSISTENCE_MASK  | 0xFF  |

- Normal: An event can be lost due to low bandwidth or disk space constraints.
- Critical: Used for events that should be prioritized over non-critical events.
- Default: Default combination of flags (same as normal).
- PersistenceMask: Mask for persistence flags.
