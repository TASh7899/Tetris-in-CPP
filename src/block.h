#pragma once
#include <map>
#include "position.h"
#include <vector>
#include <raylib.h>

class Block{
public:
    Block();
    int id;
    std::map<int, std::vector<position>> cells;
    std::vector<position> GetCellPosition();
    void Draw(int x, int y);
    void Move(int n, int m);
    void Rotate();
    void undoRotation();
private:
    int RotationState;
    int cellSize;
    int RowOffset;
    int ColumnOffset;
    std::vector<Color> colors;


};