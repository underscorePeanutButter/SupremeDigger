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
    double _vX = 0;
    double _vY = 0;
    
    // available power when underground (powered by solar)
    const double _CHARGE_SPEED = 10;
    
    double _maxBattery = 100;
    double _battery = 100;
    
    // movement speed
    double groundSpeed = 1;
    double airSpeed = 0.75;
    double digSpeed = 0.5;
    
    // appearance
    SDL_Color color = { 0xFF, 0x00, 0x00, 0xFF };
    
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
