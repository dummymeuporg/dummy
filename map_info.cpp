#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <fstream>

#include "map.hpp"

int main(int argc, char* argv[])
{

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " MAP_FILE" << std::endl;
        ::exit(EXIT_FAILURE);
    }

    try {
        std::ifstream ifs(argv[1], std::ifstream::in | std::ifstream::binary);
        Dummy::Version0001Map map(ifs);
        ifs.close();
    } catch(std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        ::exit(EXIT_FAILURE);
    }


    return EXIT_SUCCESS;
}

