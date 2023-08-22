#include <SDL.h>
#include <ctime>
#include <iostream>

#define CirColour 0x99
#define SquarColour 0x44

// Limit loop rate for visibility
#define LIMIT_RATE 0
// Tick-rate in milliseconds (if LIMIT_RATE == 1)
#define TICK_RATE 50

// Standard Library
using namespace std;

// Width and height (in pixels) of a Dot
unsigned int DotSize = 1;

// System dimensions (the dimension of the objects relatively to the each other)
unsigned int SystemWidth = 640 / DotSize;
unsigned int SystemHeight = SystemWidth;

// Graphics
SDL_Window* window = NULL;
SDL_Surface* surface = NULL;
unsigned int WindowWidth = SystemWidth * DotSize;
unsigned int WindowHeight = SystemHeight * DotSize;

void DrawDot(unsigned int x, unsigned int y, unsigned int colour)
{

    Uint8* pixel_ptr = (Uint8*)surface->pixels + (y * DotSize * WindowWidth + x * DotSize) * 4;

    for (unsigned int i = 0; i < DotSize; i++)
    {
        for (unsigned int j = 0; j < DotSize; j++)
        {
            *(pixel_ptr + j * 4) = colour;     // r
            *(pixel_ptr + j * 4 + 1) = colour; // g
            *(pixel_ptr + j * 4 + 2) = colour; // b
        }
        pixel_ptr += WindowWidth * 4;
    }
}

int main(int argc, char* argv[])
{

    srand(time(NULL));

    // SDL boilerplate
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Estimate Pi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WindowWidth, WindowHeight, SDL_WINDOW_SHOWN);
    surface = SDL_GetWindowSurface(window);

    unsigned int ray = SystemWidth;
    unsigned int xDot, yDot;
    unsigned int CircleDots = 0;
    unsigned int TotalDots = 0;
    unsigned int Distance;
    long double Pi;

    // SDL Event handler
    SDL_Event e;

    cout << "Processing...\n";

    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
            if (e.type == SDL_QUIT)
                quit = true;

        xDot = rand() % SystemWidth;
        yDot = rand() % SystemHeight;
        Distance = xDot * xDot + yDot * yDot;
        if (Distance < ray * ray)
        {
            CircleDots++;
            DrawDot(xDot, yDot, CirColour);
        }
        else
            DrawDot(xDot, yDot, SquarColour);
        TotalDots++;

        // Update frame buffer
        SDL_UpdateWindowSurface(window);

#if LIMIT_RATE
        SDL_Delay(TICK_RATE);
#endif
    }
    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    system("cls");

    Pi = (long double)4 * ((long double)CircleDots / (long double)TotalDots);
    cout << "Pi: " << Pi << endl;
    system("pause");

    return 0;
}