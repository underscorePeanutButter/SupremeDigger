#ifndef digger_hpp
#define digger_hpp

#include <cstdio>
#include <SDL2/SDL.h>

#include "constants.hpp"
using namespace std;

class Digger {
private:
    const int _WIDTH = TILE_SIZE;
    const int _HEIGHT = TILE_SIZE;
    
    double _x;
    double _y;
    double _vX = 0;
    double _vY = 0;
    
    // available power when underground (powered by solar)
    const double _CHARGE_SPEED = 10;
    
    double _maxBattery = 100;
    double _battery = 100;
    
    // movement speed
    double _groundSpeed = 1;
    double _airSpeed = 0.75;
    double _digSpeed = 0.5;
    
    // appearance
    const SDL_Color *_color = &RED;
    
public:
    Digger();
    Digger(int x, int y);
    
    void setX(double x);
    void setY(double y);
    
    void setVX(double vX);
    void setVY(double vY);
    
    void accelerate(double x, double y);
    void stop();
    
    void draw(SDL_Renderer *renderer);
};

#endif
