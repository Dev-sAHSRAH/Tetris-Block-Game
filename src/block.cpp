#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;

    colors = GetCellColors();
    rowOffset = 0;
    colOffset = 0;
}

void Block::Draw()
{
    std::vector<Position> tiles = GetCellPositions();

    for (Position item : tiles)
    {
        // DrawRectangle(x,y,w,h,color)
        DrawRectangle(item.col * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    colOffset += columns;
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];

    std::vector<Position> movedTiles;
    for (Position item : tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.col + colOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}