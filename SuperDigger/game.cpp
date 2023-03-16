#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "game.hpp"
#include "digger.hpp"
#include "block.hpp"
using namespace std;

Digger player;

// called once per frame. update game objects.
bool updateGame(const Uint8 *keyboardState) {
    
    
    return true;
}

// called once per frame. draw game objects.
bool drawGame(SDL_Renderer *renderer) {
    player.draw(renderer);
    
    return true;
}

// called at launch. initialize game objects.
bool initGame() {
    srand(static_cast<unsigned int>(time(NULL)));
    
    Map newMap;
    newMap.generateMap();
    
    player.setX(0);
    player.setY(0);
    
    return true;
}

// called at exit. destroy dynamic game objects.
void cleanUpGame() {
    
}
