#include <raylib.h>
#include "game.h"

class Screen
{
    static Color bg;

public:
    static void setBg()
    {
        ClearBackground(bg);
    }

    static void setScreen()
    {
        InitWindow(300, 600, "Tetris Game");
        SetTargetFPS(60);
    }
};

Color Screen ::bg = {44, 44, 127, 255};

int main()
{

    Screen::setScreen();

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        BeginDrawing();

        Screen::setBg();

        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}