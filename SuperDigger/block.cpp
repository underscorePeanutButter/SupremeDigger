#include <cstdlib>

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

bool shouldGenerate(int testX, int testY, double spawnChance) {
    int percentage = rand() % 100;
    spawnChance *= (testY / (static_cast<double>(MAP_HEIGHT) - GROUND_HEIGHT)) * 100;
    
    if (spawnChance > percentage) {
        return true;
    }
    
    return false;
}

bool Map::generateMap() {
    // generate a new map
    const int MIN_SPAWN_CHANCES = 100;
    
    const double COAL_SPAWN_CHANCE = 1;
    const int MIN_COAL_SEEDS = 30;
    
    const double SILVER_SPAWN_CHANCE = 0.5;
    const int MIN_SILVER_SEEDS = 20;
    
    const double GOLD_SPAWN_CHANCE = 0.25;
    const int MIN_GOLD_SEEDS = 10;
    
    const double DIAMOND_SPAWN_CHANCE = 0.1;
    const int MIN_DIAMOND_SEEDS = 5;
    
    // generate coal
    int numCoalSeeds = 0;
    for (int i = 0; numCoalSeeds < MIN_COAL_SEEDS || i < MIN_SPAWN_CHANCES; i++) {
        int testX = rand() % MAP_WIDTH;
        int testY = rand() % (MAP_HEIGHT - GROUND_HEIGHT) + GROUND_HEIGHT;
        
        bool generating = shouldGenerate(testX, testY, COAL_SPAWN_CHANCE);
    }
    
    return true;
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
