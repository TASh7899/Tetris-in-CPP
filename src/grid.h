#pragma once
#include <raylib.h>
#include<vector>

class Grid{
    public:
        Grid();
        int grid[20][10];
        void initialize();
        void Draw();
        bool IsCellOutside(int row, int col);
        bool IsCellEmpty(int r, int c);
        int ClearFullRows();

    private:
        int NumRows;
        int NumCols;
        int Cellsize;
        bool IsRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int NumClrRow);
        std::vector<Color> colors;
};