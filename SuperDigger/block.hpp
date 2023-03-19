#ifndef block_hpp
#define block_hpp

#include <cstdio>
#include <string>
#include <SDL2/SDL.h>

#include "constants.hpp"
using namespace std;

enum TILE_TYPE {
    AIR,
    DIRT,
    COAL,
    SILVER,
    GOLD,
    DIAMOND
};

const int resourceValues[5] = { 0, 10, 50, 150, 500 };
const SDL_Color resourceColors[5] = { BROWN, DARK_GREY };

class Block {
private:
    const int _WIDTH = TILE_SIZE;
    const int _HEIGHT = TILE_SIZE;
    
    int _x;
    int _y;
    
    enum TILE_TYPE _type = AIR;
    
public:
    Block();
    Block(int x, int y, enum TILE_TYPE type);
    
    double getX();
    double getY();
    
    void setX(int x);
    void setY(int y);
    
    int getType();
    void setType(enum TILE_TYPE type);
    
    void draw(SDL_Renderer *renderer);
};

class Map {
private:
    enum TILE_TYPE _rawMap[MAP_HEIGHT][MAP_WIDTH];   // store all map data read from map file
    Block _map[MAP_HEIGHT][MAP_WIDTH];               // store the map as block objects
    
public:
    Map();
    
    bool generateMap();
    
    bool loadMap(string filename);
    bool processMap();
    
    Block *getBlock(int x, int y);
    void destroyBlock(int x, int y);
    
    void draw(SDL_Renderer *renderer, int startY = 0, int endY = MAP_HEIGHT);
};

#endif
