#include <cstdlib>

#include "block.hpp"

Block::Block() {
    
}

Block::Block(int x, int y, enum TILE_TYPE type) {
    _x = x;
    _y = y;
    _type = type;
}

int Block::getWidth() {
    return _WIDTH;
}

int Block::getHeight() {
    return _HEIGHT;
}

double Block::getX() {
    return _x;
}

double Block::getY() {
    return _y;
}

void Block::setX(int x) {
    _x = x;
}

void Block::setY(int y) {
    _y = y;
}

int Block::getType() {
    return _type;
}

void Block::setType(enum TILE_TYPE type) {
    _type = type;
}

void Block::draw(SDL_Renderer *renderer) {
    // create rect and fill with _color
    if (_type != AIR) {
        const SDL_Color color = resourceColors[_type];
        
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_Rect blockRect = { _x, _y, _WIDTH, _HEIGHT };
        
        SDL_RenderFillRect(renderer, &blockRect);
    }
}

Map::Map() {
    // fill map with dirt
    for (int y = 0; y < 400; y++) {
        for (int x = 0; x < 50; x++) {
            _map[y][x].setX(x * TILE_SIZE);
            _map[y][x].setY(y * TILE_SIZE);
            
            if (y >= GROUND_HEIGHT) {
                _map[y][x].setType(DIRT);
            }
        }
    }
}

//bool shouldGenerate(int testX, int testY, double spawnChance) {
//    int percentage = rand() % 100;
//    spawnChance *= (testY / (static_cast<double>(MAP_HEIGHT) - GROUND_HEIGHT)) * 100;
//
//    if (spawnChance > percentage) {
//        return true;
//    }
//
//    return false;
//}

bool Map::generateMap() {
//    // generate a new map
//    const int MIN_SPAWN_CHANCES = 100;
//
//    const double COAL_SPAWN_CHANCE = 1;
//    const int MIN_COAL_SEEDS = 30;
//
//    // generate coal
//    int numSeeds = 0;
//    for (int i = 0; numSeeds < MIN_COAL_SEEDS || i < MIN_SPAWN_CHANCES; i++) {
//        int testX = rand() % MAP_WIDTH;
//        int testY = rand() % (MAP_HEIGHT - GROUND_HEIGHT) + GROUND_HEIGHT;
//
//        if(shouldGenerate(testX, testY, COAL_SPAWN_CHANCE)) {
//            numSeeds++;
//            _map[testY][testX].setType(COAL);
//        }
//    }
    
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
