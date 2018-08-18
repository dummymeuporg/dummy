#pragma once

#include <cstdint>
#include <iosfwd>
#include <vector>

namespace Dummy {

    class Version0001Map
    {
    public:
        friend class Version0001MapReader;
        const std::uint32_t MAGIC_WORD = 0xF000BABA;
        const std::uint16_t LATEST_VERSION = 0x0001;
        Version0001Map(std::ifstream&);
        Version0001Map(std::uint16_t, std::uint16_t);

    private:
        std::uint16_t m_version;
        std::uint16_t m_width, m_height;
        std::vector<bool> m_blockingTiles;
    };
}
