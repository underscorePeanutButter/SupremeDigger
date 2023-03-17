#ifndef game_hpp
#define game_hpp

#include <SDL2/SDL.h>

bool initGame();
void cleanUpGame();

bool updateGame(const Uint8 *keyboardState);
bool drawGame(SDL_Renderer *renderer);

#endif
