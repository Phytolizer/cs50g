// cs50g.cpp : Defines the entry point for the application.
//

#include "GraphicsContext.hpp"
#include "MySDL.hpp"
#include "SmartRenderer.hpp"
#include "SmartSurface.hpp"
#include "SmartWindow.hpp"
#include "Sprite.hpp"

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

int main(int /*argc*/, char** /*argv*/)
{
    const GraphicsContext gc;
    TTF_Font* font = mysdl::CheckPointer(TTF_OpenFont("res/font.ttf", 12));
    const SmartWindow window{"Pong",       SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                             WINDOW_WIDTH, WINDOW_HEIGHT,           SDL_WINDOW_ALLOW_HIGHDPI};
    const SmartRenderer renderer{window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC};
    const Sprite text{SmartTexture{
        renderer, SmartSurface{TTF_RenderText_Blended(font, "Hello Pong!", SDL_Color{255, 255, 255, 255})}}};

    bool run = true;
    while (run)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                run = false;
                break;
            default:
                break;
            }
        }

        renderer.setDrawColor(SDL_Color{0, 0, 0, 255});
        renderer.clear();
        renderer.copy(text);
        renderer.present();
    }

    TTF_CloseFont(font);
    return 0;
}
