#include <memory>

#include "mapreader.hpp"
#include "version0001mapreader.hpp"

Dummy::MapReader*
Dummy::MapReader::getMapReader(std::uint16_t version)
{
    switch (version)
    {
    case 0x0001:
        return new Dummy::Version0001MapReader();
        break;
    default:
        return new Dummy::Version0001MapReader();
    }
}
