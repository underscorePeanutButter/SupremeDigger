// write shitty code ;-;

#include <cstdio>
#include <SDL2/SDL.h>
using namespace std;

SDL_Window *window;
SDL_Renderer *renderer;

bool init();
void cleanUp();

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main() {
    if (!init()) {
        return -1;
    }
    
    SDL_Event e;
    
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }
        
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);
        
        SDL_RenderPresent(renderer);
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
    
    return true;
}

void cleanUp() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = NULL;
    renderer = NULL;
    
    SDL_Quit();
}
