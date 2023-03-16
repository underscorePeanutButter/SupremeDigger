#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

bool init();
void cleanUp();

bool update(const Uint8 *keyboardState);
bool draw(SDL_Renderer *renderer);

#endif
