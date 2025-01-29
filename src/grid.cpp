#include "grid.h"
#include "colors.h"

Grid::Grid()
{
    NumCols = 10;
    NumRows = 20;
    Cellsize = 30;
    colors = GetColors();
    initialize();
}

void Grid::initialize()
{
    for(int i = 0; i < NumRows; i++)
    {
        for(int j = 0; j < NumCols; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void Grid::Draw()
{
    for(int i = 0; i < NumRows; i++)
    {
        for(int j = 0; j < NumCols; j++)
        {
            int cellcolor = grid[i][j]; 
            DrawRectangle(j * Cellsize + 41, i * Cellsize + 41, Cellsize-3, Cellsize-3, colors[cellcolor]);
        }
    }
}

bool Grid::IsCellOutside(int row, int col)
{
    if(row >= 0 && row < NumRows && col >= 0 && col < NumCols)
    {
        return false;
    }

    else{
        return true;
    }
}

bool Grid::IsCellEmpty(int r, int c)
{
    if(grid[r][c] == 0)
    {
        return true;
    }
    return false;
}

bool Grid::IsRowFull(int row)
{
    for(int col = 0; col < NumCols; col++)
    {
        if(grid[row][col] == 0)
        {
            return false;
        } 
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for ( int col = 0; col < NumCols; col++)
    {
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int NumClrRow)
{
    for ( int col = 0; col < NumCols; col++)
    {
        grid[row + NumClrRow][col] = grid[row][col];
        grid[row][col] = 0;
    }
}

int Grid::ClearFullRows()
{
    int complete = 0;
    for(int row = NumRows - 1; row >= 0; row--)
    {
        if(IsRowFull(row))
        {
            ClearRow(row);
            complete++;
        }
        else if(complete > 0)
        {
            MoveRowDown(row, complete);
            
        }

    
    } 
    return complete;
}
