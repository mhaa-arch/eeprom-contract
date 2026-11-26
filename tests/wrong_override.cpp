#include <eeprom/memory.hpp>

using namespace mhaa::eeprom;

class WrongOverride final : public Memory
{
public:
    uint32_t size_bytes() override;
};
