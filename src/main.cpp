#include <raylib.h>
#include "game.h"
#include <iostream>

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
        InitWindow(500, 620, "Tetris Game");
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

class Time
{
private:
    double lastUpdateTime = 0;

    friend class EventManage;
};

Time t;

class EventManage
{
public:
    static bool EventTriggered(double interval)
    {
        double currentTime = GetTime();
        if (currentTime - t.lastUpdateTime >= interval)
        {
            t.lastUpdateTime = currentTime;
            return true;
        }
        return false;
    }
};

// Colors in raylib - struct Color = {r,g,b,alpha};
Color *Screen::bg = new Color{44, 44, 127, 255};

int main()
{

    Screen::setScreen();
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    Game game = Game();

    // Game loop
    while (WindowShouldClose() == false)
    {

        game.HandleInput();

        if (EventManage::EventTriggered(0.5))
        {
            game.MoveBlockDown();
        }

        // To create a blank canvas
        BeginDrawing();

        Screen::setBg();
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);

        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        game.Draw();

        // To remove the canvas
        EndDrawing();
    }

    Screen::removeScreen();

    return 0;
}