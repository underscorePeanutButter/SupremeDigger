#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "game.hpp"
#include "digger.hpp"
#include "block.hpp"
using namespace std;

Digger player;
Map world;

// called once per frame. update game objects.
bool updateGame(const Uint8 *keyboardState) {
    player.update(keyboardState, &world);
    
    return true;
}

// called once per frame. draw game objects.
bool drawGame(SDL_Renderer *renderer) {
    world.draw(renderer);
    player.draw(renderer);
    
    return true;
}

// called at launch. initialize game objects.
bool initGame() {
    player.setX(0);
    player.setY(0);
    
    world.generateMap();
    
    return true;
}

// called at exit. destroy dynamic game objects.
void cleanUpGame() {
    
}
