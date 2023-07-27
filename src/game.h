#pragma once
#include "grid.h"
#include "blocks.cpp"

// This class will serve as a conatiner for all elements of our game.
class Game
{
public:
    Game();

    Block GetRandomBlock();

    std::vector<Block> GetAllBlocks();

    void Draw();
    void HandleInput();

    void MoveBlockLeft();

    void MoveBlockRight();

    void MoveBlockDown();

    Grid grid;

private:
    bool IsBlockOutside();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};