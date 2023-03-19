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

int Digger::collideBlock(Block *block) {
    bool alignedX = false;
    bool alignedY = false;
    
    bool movingRight = false;
    bool movingLeft = false;
    bool movingUp = false;
    bool movingDown = false;
    
    if (_y + _vY + _HEIGHT > block->getY() &&
        _y + _vY < block->getY() + block->getHeight()) {
        // player is aligned on y axis
        alignedY = true;
    }
    
    if (_x + _vX + _WIDTH > block->getX() &&
        _x + _vX < block->getX() + block->getWidth()) {
        // player is aligned on x axis
        alignedX = true;
    }
    
    if (_vX > 0) {
        // the player is moving right
        movingRight = true;
    } else if (_vX < 0) {
        // the player is moving left
        movingLeft = true;
    }
    
    if (_vY > 0) {
        // the player is moving down
        movingDown = true;
    } else if (_vY < 0) {
        // the player is moving up
        movingUp = true;
    }
    
    if (alignedX && alignedY) {
        if (movingDown) {
            return UP;
        }
        
        if (movingUp) {
            return DOWN;
        }
        
        if (movingRight) {
            return LEFT;
        }
        
        if (movingLeft) {
            return RIGHT;
        }
    }
    
    return -1;
}

MapCollisionStruct *Digger::collideMap(Map *map) {
    MapCollisionStruct *newStruct = new MapCollisionStruct;
    
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            Block *block = map->getBlock(x, y);
            int collisionResult = collideBlock(block);
            
            if (collisionResult >= 0) {
                newStruct->block = block;
                newStruct->direction = collisionResult;
                
                return newStruct;
            }
        }
    }
    
    delete newStruct;
    return NULL;
}

bool Digger::update(const Uint8 *keyboardState, Map *map) {
    if (keyboardState[SDL_SCANCODE_LEFT]) {
        accelerate(-_groundSpeed / 10, 0);
    }
    
    if (keyboardState[SDL_SCANCODE_RIGHT]) {
        accelerate(_groundSpeed / 10, 0);
    }
    
    if (!keyboardState[SDL_SCANCODE_LEFT] && !keyboardState[SDL_SCANCODE_RIGHT]) {
        if (_vX > 0) {
            accelerate(-_FRICTION, 0);
        } else if (_vX < 0) {
            accelerate(_FRICTION, 0);
        }
        
        if (abs(_vX) < _groundSpeed / 10) {
            setVX(0);
        }
    }
    
    if (_vX > _groundSpeed) {
        _vX = _groundSpeed;
    } else if (_vX < -_groundSpeed) {
        _vX = -_groundSpeed;
    }
    
    if (!_grounded) {
        _vY += GRAVITY;
    }
    
    if (_vY > TERMINAL_VELOCITY) {
        _vY = TERMINAL_VELOCITY;
    }
    
    MapCollisionStruct *collisionResult = collideMap(map);
    if (collisionResult) {
        if (collisionResult->block->getType() != AIR) {
            if (collisionResult->direction == UP) {
                _vY = 0;
                _y = collisionResult->block->getY() - _HEIGHT;
                _grounded = true;
            }
        }
        
        delete collisionResult;
        
    }
    
    _x += _vX;
    _y += _vY;
    
    return true;
}

void Digger::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, _color->r, _color->g, _color->b, _color->a);
    SDL_Rect diggerRect = { static_cast<int>(_x), static_cast<int>(_y), _WIDTH, _HEIGHT };
    
    SDL_RenderFillRect(renderer, &diggerRect);
}
