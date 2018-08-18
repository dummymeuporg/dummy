#pragma once

#include "mapreader.hpp"

namespace Dummy
{
    class Version0001Map;
    class Version0001MapReader : public MapReader
    {
    public:
        virtual void readMap(Dummy::Version0001Map&, std::ifstream&)
            const override;
    };
}
