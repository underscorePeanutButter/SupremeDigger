#include "block.hpp"

// never use this
Block::Block() {
    
}

Block::Block(int x, int y, enum TILE_TYPE type) {
    _x = x;
    _y = y;
    _type = type;
}

void Block::setType(enum TILE_TYPE type) {
    _type = type;
}

void Block::draw(SDL_Renderer *renderer) {
    // create rect and fill with _color
    
}

Map::Map() {
    
}

bool Map::loadMap(string filename) {
    // read file and place everything in rawMap
    
    return true;
}

bool Map::processMap() {
    // use the data in rawMap to create map
    
    return true;
}

Block *Map::getBlock(int x, int y) {
    return &_map[y][x];
}

// ensure the player's inventory has been updated before calling this
void Map::destroyBlock(int x, int y) {
    _map[y][x].setType(AIR);
}

void Map::draw(SDL_Renderer *renderer, int startY, int endY) {
    for (int y = startY; y < endY && y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            _map[y][x].draw(renderer);
        }
    }
}
