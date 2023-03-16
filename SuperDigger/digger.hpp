#ifndef digger_hpp
#define digger_hpp

#include <cstdio>
#include <SDL2/SDL.h>

class Digger {
private:
    const int _WIDTH = 16;
    const int _HEIGHT = 16;
    
    double _x;
    double _y;
    double _vX;
    double _vY;
    
    // available power when underground (powered by solar)
    const double _CHARGE_SPEED = 10;
    
    double _maxBattery;
    double _battery;
    
    // movement speed
    double groundSpeed = 1;
    double airSpeed = 0.75;
    double digSpeed = 0.5;
    
public:
    void setX(double x);
    void setY(double y);
    
    void setVX(double vX);
    void setVY(double vY);
    
    void accelerate(double x, double y);
    void stop();
    
    void drawDigger(SDL_Renderer *renderer);
};

#endif
