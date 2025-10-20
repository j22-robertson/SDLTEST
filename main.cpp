#define SDL_MAIN_USE_CALLBACKS

#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <box2d/base.h>

#include "box2d/box2d.h"
#include "cmake-build-debug/_deps/box2d-src/src/world.h"
#include "core/Texture.h"

SDL_Window* window;
SDL_Renderer* renderer;

SDL_FRect test_rect = {200,200,64,64};

b2WorldId world_id;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv)
{
    // create a window
    window = SDL_CreateWindow("Hello, Triangle!", 960, 540, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window,nullptr);

    b2WorldDef world_def = b2DefaultWorldDef();
    world_def.gravity = (b2Vec2){0.0f,-10.0f};
    Texture texture;
    texture.LoadFromFile("../assets/images/sprite.png",renderer);
    world_id = b2CreateWorld(&world_def);
    return SDL_APP_CONTINUE;
}



SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    // close the window on request
    if (event->type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
    {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    // Draw here
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderFillRect(renderer, &test_rect);

    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    b2DestroyWorld(world_id);
}
