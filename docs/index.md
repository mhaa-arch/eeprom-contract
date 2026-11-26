# EEPROM Contract guide

The address type describes a portable byte offset. Each memory instance has a smaller or equal effective capacity reported at runtime. Start with range and timeout checks, then follow the write and update examples.

1. Start with [the contract](contract.md) for implementer obligations and capability boundaries.
2. Read [the conformance example](examples.md) for an implementation you can compile locally.
3. Consult [the portability notes](compatibility.md) before choosing a hardware mapping.