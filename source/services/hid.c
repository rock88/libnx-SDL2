#include <SDL2/SDL.h>
#include <switch.h>

static int key_map[][2] = {
    {SDL_SCANCODE_W, KEY_LSTICK_UP},
    {SDL_SCANCODE_A, KEY_LSTICK_LEFT},
    {SDL_SCANCODE_S, KEY_LSTICK_DOWN},
    {SDL_SCANCODE_D, KEY_LSTICK_RIGHT},
    {SDL_SCANCODE_UP, KEY_DUP},
    {SDL_SCANCODE_LEFT, KEY_DLEFT},
    {SDL_SCANCODE_DOWN, KEY_DDOWN},
    {SDL_SCANCODE_RIGHT, KEY_DRIGHT},
    {SDL_SCANCODE_Q, KEY_B},
    {SDL_SCANCODE_E, KEY_A},
    {SDL_SCANCODE_Y, KEY_Y},
    {SDL_SCANCODE_X, KEY_X},
    {SDL_SCANCODE_MINUS, KEY_MINUS},
    {SDL_SCANCODE_EQUALS, KEY_PLUS},
    {SDL_SCANCODE_L, KEY_L},
    {SDL_SCANCODE_R, KEY_R},
    {SDL_SCANCODE_Z, KEY_ZL},
    {SDL_SCANCODE_C, KEY_ZR},
};

static int key_count = sizeof(key_map) / sizeof(key_map[0]);

static inline HidControllerKeys hidControllerKeyFromSDLScancode(SDL_Scancode code) {
    for (int i = 0; i < key_count; i++) {
        if (key_map[i][0] == code) {
            return key_map[i][1];
        }
    }
    return 0;
}

extern SDL_Event event;

Result hidInitialize(void) {
    return 0;
}

void hidExit(void) {
    
}

void hidReset(void) {
    
}

void hidScanInput(void) {
    
}

u64 hidKeysHeld(HidControllerID id) {
    u64 result = 0;
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    
    for (int i = 0; i < key_count; i++) {
        if (state[key_map[i][0]]) {
            result |= key_map[i][1];
        }
    }
    return result;
}

u64 hidKeysDown(HidControllerID id) {
    if (event.type == SDL_KEYDOWN) {
        return hidControllerKeyFromSDLScancode(event.key.keysym.scancode);
    }
    return 0;
}

u64 hidKeysUp(HidControllerID id) {
    if (event.type == SDL_KEYUP) {
        return hidControllerKeyFromSDLScancode(event.key.keysym.scancode);
    }
    return 0;
}

void hidJoystickRead(JoystickPosition *pos, HidControllerID id, HidControllerJoystick stick) {
    
}
