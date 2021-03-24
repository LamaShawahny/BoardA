
#pragma once
#include <vector>
#include <string>
#include "Direction.hpp"
namespace ariel{
    class Board{
    private:
            std::vector<std::string> board;
            unsigned int horizontalyStart=INT32_MAX;
            unsigned int horizontalyEnd=0;
            unsigned int start=INT32_MAX;
            unsigned int end=0;
    public:
        Board() noexcept: board(0,"_"){};
        void post(unsigned int i, unsigned int j, Direction d, const std::string &message);
        std::string read(unsigned int i, unsigned int j, Direction d, unsigned int length);
        void show();
    };

}