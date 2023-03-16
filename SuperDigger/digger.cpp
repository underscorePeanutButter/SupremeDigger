#include "digger.hpp"

// constructor and deconstructor
Digger::Digger() {
    
}

Digger::Digger(int x, int y) {
    _x = x;
    _y = y;
}

// set x position
void Digger::setX(double x) {
    _x = x;
}

// set y position
void Digger::setY(double y) {
    _y = y;
}

// set horizontal velocity
void Digger::setVX(double vX) {
    _vX = vX;
}

// set vertical velocity
void Digger::setVY(double vY) {
    _vY = vY;
}

// add to the digger's velocity
void Digger::accelerate(double aX, double aY) {
    _vX += aX;
    _vY += aY;
}

// stop all movement
void Digger::stop() {
    setVX(0);
    setVY(0);
}

void Digger::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect diggerRect = { static_cast<int>(_x), static_cast<int>(_y), _WIDTH, _HEIGHT };
    
    SDL_RenderFillRect(renderer, &diggerRect);
}
