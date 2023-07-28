#pragma once
#include "grid.h"
#include "blocks.cpp"
#include "SoundManager.h"
class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;
    Music music;
    // void UpdateMusicStream();

private:
    void MoveBlockLeft();
    void MoveBlockRight();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    Grid grid;
    std::vector<Block> blocks;

    SoundManager *soundManager;

    Block currentBlock;
    Block nextBlock;
    // Sound rotateSound;
    // Sound clearSound;
};