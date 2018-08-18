#include <fstream>

#include "map.hpp"
#include "mapreader.hpp"

Dummy::Version0001Map::Version0001Map(std::ifstream& ifs)
{
    std::uint32_t magicWord;
    ifs.clear();
    ifs.seekg(0);
    ifs.read(reinterpret_cast<char*>(&magicWord), sizeof(std::uint32_t));
    if (magicWord != Dummy::Version0001Map::MAGIC_WORD)
    {
        //XXX: Throw an exception?
    }
    ifs.read(reinterpret_cast<char*>(&m_version), sizeof(std::uint16_t));

    Dummy::MapReader* reader = Dummy::MapReader::getMapReader(m_version);
    reader->readMap(*this, ifs);
    delete reader;
}

Dummy::Version0001Map::Version0001Map(std::uint16_t width,
                                      std::uint16_t height)
    : m_width(width), m_height(height)
{
}
