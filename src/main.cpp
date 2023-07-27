#include <raylib.h>
#include "game.h"

class Screen
{
    static Color *bg;

public:
    static void setBg()
    {
        // Clears the window's background with provided color.
        ClearBackground(*bg);
    }

    static void setScreen()
    {
        // to create a new window
        InitWindow(300, 600, "Tetris Game");
        // FPS - Frames per second
        SetTargetFPS(60);
    }

    static void releaseMemory()
    {
        delete[] bg;
    }

    static void removeScreen()
    {
        CloseWindow();
    }

    // Destructor to deallocate memory
    ~Screen()
    {
        releaseMemory();
    }
};

// Colors in raylib - struct Color = {r,g,b,alpha};
Color *Screen::bg = new Color{44, 44, 127, 255};

int main()
{

    Screen::setScreen();

    Game game = Game();

    // Game loop
    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        // To create a blank canvas
        BeginDrawing();

        Screen::setBg();

        game.Draw();

        // To remove the canvas
        EndDrawing();
    }

    Screen::removeScreen();

    return 0;
}