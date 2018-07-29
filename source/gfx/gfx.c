#include <SDL2/SDL.h>
#include <switch.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static SDL_Surface *surface = NULL;

size_t g_gfx_framebuf_width=0, g_gfx_framebuf_aligned_width=0;
size_t g_gfx_framebuf_height=0, g_gfx_framebuf_aligned_height=0;
size_t g_gfx_framebuf_display_width=0, g_gfx_framebuf_display_height=0;
size_t g_gfx_singleframebuf_size=0;
size_t g_gfx_singleframebuf_linear_size=0;

bool g_gfx_drawflip = false;

#define SAFE_FREE(ptr, func) \
if (ptr) { \
    func(ptr); \
    ptr = NULL; \
}

void gfxInitDefault(void) {
    gfxInitResolution(1280, 720);
}

void gfxExit(void) {
    SAFE_FREE(window, SDL_DestroyWindow);
    SAFE_FREE(renderer, SDL_DestroyRenderer);
    SAFE_FREE(surface, SDL_FreeSurface);
}

void gfxInitResolution(u32 width, u32 height) {
    gfxExit();
    
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &window, &renderer);
    
    void *data = malloc(width * height * 4);
    surface = SDL_CreateRGBSurfaceFrom(data, width, height, 32, width * 4, 0, 0, 0, 0);
    
    g_gfx_framebuf_width = width;
    g_gfx_framebuf_height = height;
    
    g_gfx_framebuf_display_width = g_gfx_framebuf_width;
    g_gfx_framebuf_display_height = g_gfx_framebuf_height;
    
    g_gfx_framebuf_aligned_width = g_gfx_framebuf_width;
    g_gfx_framebuf_aligned_height = g_gfx_framebuf_height;
    
    g_gfx_singleframebuf_size = g_gfx_framebuf_aligned_width * g_gfx_framebuf_aligned_height*4;
    g_gfx_singleframebuf_linear_size = g_gfx_framebuf_width * g_gfx_framebuf_height*4;
}

void gfxInitResolutionDefault(void) {
    gfxInitResolution(1280, 720);
}

void gfxConfigureCrop(s32 left, s32 top, s32 right, s32 bottom) {
    
}

void gfxConfigureResolution(s32 width, s32 height) {
    gfxInitResolution(width, height);
}

void gfxConfigureAutoResolution(bool enable, s32 handheld_width, s32 handheld_height, s32 docked_width, s32 docked_height) {
    
}

void gfxConfigureAutoResolutionDefault(bool enable) {
    
}

void gfxWaitForVsync(void) {
    
}

void gfxSwapBuffers(void) {
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
}

u8* gfxGetFramebuffer(u32* width, u32* height) {
    gfxGetFramebufferResolution(width, height);
    return surface->pixels;
}

void gfxGetFramebufferResolution(u32* width, u32* height) {
    if (width) {
        *width = (u32)g_gfx_framebuf_width;
    }
    if (height) {
        *height = (u32)g_gfx_framebuf_height;
    }
}

size_t gfxGetFramebufferSize(void) {
    return surface->pitch * surface->h;
}

void gfxSetMode(GfxMode mode) {
    
}

void gfxSetDrawFlip(bool flip) {
    g_gfx_drawflip = flip;
}

void gfxConfigureTransform(u32 transform) {
    
}

void gfxFlushBuffers(void) {
    
}
