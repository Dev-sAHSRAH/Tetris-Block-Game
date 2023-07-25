#include "grid.h"
#include <iostream>
#include "colors.h"

Grid ::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
}

void Grid::Initialize()
{

    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            grid[row][col] = 0;
        }
    }

    colors = GetCellColors();
}

void Grid::Print()
{
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            int cellValue = grid[row][col];
            // DrawRectangle(x,y,w,h,color);
            DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 and row < numRows and column >= 0 and column < numCols)
    {
        return false;
    }

    return true;
}