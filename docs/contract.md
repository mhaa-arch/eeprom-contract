# EEPROM contract

## Capacity is an instance property

[Memory](../include/eeprom/memory.hpp) describes byte-addressable nonvolatile storage. `Address` is a 32-bit byte offset so one interface can cover different regions. `size_bytes()` reports the number of accessible bytes. Before addressing hardware, check that the offset is strictly below that count. An address that fits the type can still return `InvalidAddress`. The largest representable capacity is `UINT32_MAX` bytes, with the last usable offset one less than capacity.

## Completion and errors

Both operations take a positive millisecond budget. Zero is `InvalidArgument`, and `UINT32_MAX` is finite. The time base must progress in the calling context. `Busy` means the operation could not start, `Timeout` means completion could not be confirmed, and `Error` means the operation failed. A failed read preserves the output byte. `Success` on write means programming completed. A timeout or error can still leave a changed cell, so design recovery around the uncertain result.

## Implementation boundary

The Adapter owns resource state. The caller must keep the implementation alive during each call and arrange access from other execution contexts. Document the contexts and concurrency guarantees of the actual implementation. Shared public types are in [`eeprom/types.hpp`](../include/eeprom/types.hpp).
