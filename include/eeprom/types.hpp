#ifndef MHAA_EEPROM_TYPES_HPP
#define MHAA_EEPROM_TYPES_HPP

#include <stdint.h>

namespace mhaa
{
    namespace eeprom
    {
        using Address = uint32_t;

        enum class Status
        {
            Success,
            Busy,
            InvalidAddress,
            InvalidArgument,
            Timeout,
            Error
        };
    }
}

#endif
