#ifndef constants_hpp
#define constants_hpp

#include <SDL2/SDL.h>

constexpr int TILE_SIZE = 16;
constexpr int GROUND_HEIGHT = 5;

constexpr int MAP_WIDTH = 50;
constexpr int MAP_HEIGHT = 400;

constexpr double GRAVITY = 0.1;
constexpr double TERMINAL_VELOCITY = 2;

constexpr SDL_Color RED = { 0xFF, 0x00, 0x00, 0xFF };
constexpr SDL_Color GREEN = { 0x00, 0xFF, 0x00, 0xFF };
constexpr SDL_Color BLUE = { 0x00, 0x00, 0xFF, 0xFF };
constexpr SDL_Color BROWN = { 0x80, 0x60, 0x00, 0xFF };
constexpr SDL_Color DARK_GREY = { 0x4A, 0x49, 0x48, 0xFF };

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

#endif
