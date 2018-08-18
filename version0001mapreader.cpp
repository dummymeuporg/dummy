#include <iostream>
#include <fstream>
#include <vector>

#include "version0001mapreader.hpp"
#include "map.hpp"


void
Dummy::Version0001MapReader::readMap(Dummy::Version0001Map& map,
                                     std::ifstream& ifs)
const
{
    ifs.read(reinterpret_cast<char*>(&map.m_width), sizeof(std::uint16_t));
    ifs.read(reinterpret_cast<char*>(&map.m_height), sizeof(std::uint16_t));

    std::cout << "Dimensions: " << map.m_width << "x" << map.m_height
              << std::endl;

    std::uint32_t size;
    ifs.read(reinterpret_cast<char*>(&size), sizeof(std::uint32_t));
    std::cout << "Chipset string size: " << size << std::endl;
    std::cout << ifs.tellg() << std::endl;
    ifs.seekg(size, std::ios_base::cur);

    ifs.read(reinterpret_cast<char*>(&size), sizeof(std::uint32_t));
    std::cout << "Music string size: " << size << std::endl;
    ifs.seekg(size, std::ios_base::cur);
    ifs.seekg(map.m_width * map.m_height * 4 * 3, std::ios_base::cur);
    std::cout << ifs.tellg() << std::endl;
    map.m_blockingTiles.resize(map.m_width * map.m_height);
    for(auto it = map.m_blockingTiles.begin();
        it != map.m_blockingTiles.end(); ++it)
    {
        bool b;
        ifs.read(reinterpret_cast<char*>(&b), sizeof(bool));
        std::cout << b << " ";
    }
    std::cout << std::endl;
    std::cout << ifs.tellg() << std::endl;
}
