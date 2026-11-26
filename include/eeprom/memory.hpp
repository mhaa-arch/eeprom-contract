#ifndef MHAA_EEPROM_MEMORY_HPP
#define MHAA_EEPROM_MEMORY_HPP

#include <stdint.h>
#include <eeprom/types.hpp>

namespace mhaa
{
    namespace eeprom
    {
        /** @brief Byte-addressable nonvolatile memory with bounded operations. */
        class Memory
        {
        public:
            virtual ~Memory() = default;

            virtual uint32_t size_bytes() const = 0;

            /** @brief Reads one byte. Assigns value only on Success. */
            virtual Status read(Address address, uint8_t &value, uint32_t timeout_ms) = 0;

            /** @brief Writes one byte. Success means the write has completed. */
            virtual Status write(Address address, uint8_t value, uint32_t timeout_ms) = 0;
        };
    }
}

#endif
