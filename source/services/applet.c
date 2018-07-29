#include <SDL2/SDL.h>
#include <switch.h>
#include <time.h>

static int oldTicks = 0;
static int oldFpsTicks = 0, fps = 0;
static int SCREEN_TICK_PER_FRAME = 1000 / 60;

SDL_Event event;

bool appletMainLoop(void) {
    int currentTicks = SDL_GetTicks();
    
    event.type = 0;
    event.key.keysym.scancode = 0;
    SDL_PollEvent(&event);
    
    if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
        return false;
    }
    
    if (oldTicks == 0) {
        oldTicks = oldFpsTicks = currentTicks;
    }
    
    if (currentTicks - oldFpsTicks > 1000) {
        oldFpsTicks = currentTicks;
        //printf("fps: %i\n", fps);
        fps = 0;
    }
    
    int frameTicks = currentTicks - oldTicks;
    if (frameTicks < SCREEN_TICK_PER_FRAME) {
        SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
    }
    
    oldTicks = SDL_GetTicks();
    fps++;
    return true;
}
