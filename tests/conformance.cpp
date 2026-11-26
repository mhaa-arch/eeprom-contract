#include <eeprom/memory.hpp>

#include <cassert>

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

int main()
{
    Fake fake;
    Memory &memory = fake;
    assert(memory.size_bytes() == 1);
    assert(memory.write(0, 22, 5) == Status::Success);
    uint8_t value = 7;
    assert(memory.read(1, value, 5) == Status::InvalidAddress && value == 7);
    assert(memory.read(0, value, 5) == Status::Success && value == 22);
    fake.write_status = Status::Timeout;
    assert(memory.write(0, 24, 5) == Status::Timeout);
}
