#pragma once // this ensure this header files is included only once

#include <vector>
#include <raylib.h>

class Grid
{
public:
    Grid();

    void Initialize();

    void Print();

    void Draw();

    bool IsCellOutside(int row, int column);

    int grid[20][10];

private:
    int numRows,
        numCols, cellSize;

    std::vector<Color> colors;
};