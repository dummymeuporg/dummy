#pragma once

#include <iosfwd>

namespace Dummy
{
    class Version0001Map;
    class MapReader
    {
    public:
        virtual void readMap(Dummy::Version0001Map&, std::ifstream&) const = 0;
        static MapReader* getMapReader(std::uint16_t);

    };
}
