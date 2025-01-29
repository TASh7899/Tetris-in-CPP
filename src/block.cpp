#include "block.h"
#include "colors.h"

Block::Block()
{
    id = 0;
    RotationState = 0;
    cellSize = 30;
    colors = GetColors();
    RowOffset = 0;
    ColumnOffset = 0;
}

void Block::Draw(int x, int y)
{
    std::vector<position> tiles = GetCellPosition();
    for(auto item : tiles)
    {
        DrawRectangle(item.y * cellSize + x, item.x * cellSize+ y, cellSize - 3, cellSize - 3, colors[id]);
    }

}

void Block::Move(int n, int m)
{
    RowOffset += n;
    ColumnOffset += m;
}

void Block::Rotate()
{
    RotationState++;
    if(RotationState == (int)cells.size())
    {
        RotationState = 0;
    }
}

std::vector<position> Block::GetCellPosition()
{
    std::vector<position> tiles = cells[RotationState];
    std::vector<position> newPosv;

    for(auto item : tiles)
    {
        position newPos = position(item.x + RowOffset, item.y + ColumnOffset);
        newPosv.push_back(newPos);
    }

    return newPosv;
}

void Block::undoRotation()
{
    RotationState--;
    if(RotationState == -1)
    {
        RotationState = (int) cells.size() - 1; 
    }
}

