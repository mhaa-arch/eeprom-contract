# EEPROM Contract example

[The conformance program](../tests/conformance.cpp) pairs a simulated implementation with assertions at the Contract boundary. The one-byte fake supplies a capacity of one, checks the budget and rejects offset one. The conformance program stores 22 at offset zero, verifies that an invalid read leaves a sentinel untouched, then reads 22 back. Injecting a timeout exercises error reporting without a real programming cycle.

## Implementation excerpt

This class is taken from the program. The linked source contains the test cases and any additional fixtures.

```cpp
#include <eeprom/memory.hpp>


using namespace mhaa::eeprom;

class Fake final : public Memory
{
public:
    uint32_t size_bytes() const override { return 1; }

    Status read(Address address, uint8_t &value, uint32_t timeout_ms) override
    {
        if (!timeout_ms)
        {
            return Status::InvalidArgument;
        }
        if (address >= size_bytes())
        {
            return Status::InvalidAddress;
        }
        if (read_status != Status::Success)
        {
            return read_status;
        }
        value = stored;
        return Status::Success;
    }

    Status write(Address address, uint8_t value, uint32_t timeout_ms) override
    {
        if (!timeout_ms)
        {
            return Status::InvalidArgument;
        }
        if (address >= size_bytes())
        {
            return Status::InvalidAddress;
        }
        ++writes;
        if (write_status == Status::Success)
        {
            stored = value;
        }
        return write_status;
    }

    unsigned writes = 0;
    uint8_t stored = 42;
    Status read_status = Status::Success;
    Status write_status = Status::Success;
};
```

## Build and run

From this repository root, with assertions enabled, compile the full program. A passing run exits with status 0 and prints no output. Use `conformance.exe` on Windows.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude tests/conformance.cpp -o conformance
./conformance
```

To verify enforcement of the abstract interface, compile the two negative sources separately. The first should diagnose an abstract type and the second an incompatible override.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/missing_override.cpp
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/wrong_override.cpp
```
