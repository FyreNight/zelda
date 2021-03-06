#include <iostream>
#include "pixelmap.hpp"

Pixelmap::Pixelmap(int width, int height) {
    map_ = std::vector<std::vector<bool>>(height, std::vector<bool>(width, false));
}

void Pixelmap::Print() const {
    for(int i = 0; i < map_.size(); ++i) {
        for(int j = 0; j < map_[0].size(); ++j) {
            std::cout << map_[i][j] ? '1' : '0';
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}
