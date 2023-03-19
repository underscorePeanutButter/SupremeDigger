// write shitty code ;-;

#include <cstdio>
#include <SDL2/SDL.h>

#include "game.hpp"
using namespace std;

SDL_Window *window;
SDL_Renderer *renderer;

bool init();
void cleanUp();

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int FPS = 60;

int main() {
    if (!init()) {
        return -1;
    }
    
    SDL_Event e;
    
    bool running = true;
    while (running) {
        int startTicks = SDL_GetTicks();
        
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }
        
        const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
        
        if (keyboardState[SDL_SCANCODE_RETURN]) {
            updateGame(keyboardState);
        }
        
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);
        
        drawGame(renderer);
        
        SDL_RenderPresent(renderer);
        
        int totalTicks = SDL_GetTicks() - startTicks;
        
//        printf("FPS: %d\n", 1000 / totalTicks);
        if (totalTicks < 1000 / FPS) {
            SDL_Delay(1000 / FPS - totalTicks);
        }
    }
}

bool init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL initiailzation failure.\n");
        return false;
    }
    
    window = SDL_CreateWindow("Supreme Digger", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window creation failed.\n");
        return false;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer creation failed.\n");
        return false;
    }
    
    if (!initGame()) {
        printf("Game initialization failed.\n");
        return false;
    }
    
    return true;
}

void cleanUp() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = NULL;
    renderer = NULL;
    
    SDL_Quit();
}
