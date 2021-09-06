#include <iostream>
#include <SDL2/SDL.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

// init ... The init function, it calls the SDL init function.
int init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        return -1;
    }

    return 0;
}

// createWindowContext ... Creating the window for later use in rendering and stuff.
SDL_Window *createWindowContext()
{
    //Declaring the variable the return later.
    SDL_Window *Window;

    //Creating the window and passing that reference to the previously declared variable.
    Window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 660, 500,
                              SDL_WINDOW_OPENGL);

    //Returning the newly creted Window context.
    return Window;
}


// createRenderContext ... Creating the rendering context so that I can render things to the Window.
SDL_Renderer *createRendererContext(SDL_Window *Window)
{
    //Declaring the variable for the Renderer context.
    SDL_Renderer *Renderer;

    //Create the Renderer with the window.
    Renderer = SDL_CreateRenderer(Window, -1, 0);

    //Return the Renderer.
    return Renderer;
}


// draw ... Draw a series of lines to the screen to create a triangle.
void draw()
{
    //Creating the context for SDL2.
    SDL_Window *Window = createWindowContext();

    //Creating the rendering context.
    SDL_Renderer *Renderer = createRendererContext(Window);

    //Set the draw color...
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    //Clear the screen.
    SDL_RenderClear(Renderer);

    //Setting the actual draw color.
    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    //Drawing the lines we want. (-1, 0), (0, 1), (1, 0)
    SDL_RenderDrawLine(Renderer, 10, 480, 320, 10);
    SDL_RenderDrawLine(Renderer, 640, 480, 320, 10);
    SDL_RenderDrawLine(Renderer, 10, 480, 640, 480);

    //Update the Renderer.
    SDL_RenderPresent(Renderer);
}


// main ... The main function, right now it just calls the initialization of SDL.
int main(int argc, char *argv[])
{
    //Calling the SDL init stuff.
    init();

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(draw, 0, 1);
#else
    draw();
    SDL_Delay(5000);
    SDL_Quit();
#endif

    return 0;
}
