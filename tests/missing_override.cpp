#include <eeprom/memory.hpp>

using namespace mhaa::eeprom;

class Incomplete final : public Memory
{
public:
    Status read(Address address, uint8_t &value, uint32_t timeout_ms) override;
    Status write(Address address, uint8_t value, uint32_t timeout_ms) override;
};

int main()
{
    Incomplete implementation;
    (void)implementation;
}
