#include "game.h"
#include <random>
#include <iostream>

Game::Game()
{
    grid = Grid();
    Blocks = GetAllBlocks();
    Currentblock = GetRandomBlock();
    NextBlock = GetRandomBlock();
    GameOver = false;
    Score = 0;
}

Block Game::GetRandomBlock()
{
    if(Blocks.empty())
    {
        Blocks = GetAllBlocks();
    }
    int RandomIndex = rand() % Blocks.size();
    Block b = Blocks[RandomIndex];
    Blocks.erase(Blocks.begin() + RandomIndex);
    return b; 
}


std::vector<Block> Game::GetAllBlocks()
{
    return {OBlock(), IBlock(), JBlock(), SBlock(), LBlock(), ZBlock(), TBlock()};
}

void Game::Draw() {
    grid.Draw();
    Currentblock.Draw(41, 41);
    if(NextBlock.id == 3)
    {
        NextBlock.Draw(310, 315);
    }

    else if (NextBlock.id == 4)
    {
        NextBlock.Draw(310, 325);
    }
    else
    {
        NextBlock.Draw(325, 320);
    }
}

void Game::HandleInput()
{
    int key = GetKeyPressed();

    if( GameOver && key != 0)
    {
        GameOver = false;
        Reset();
    }

    switch (key){
        case KEY_DOWN:
            MoveDown();
            updateScore(0, 1);
            break;
        case KEY_RIGHT:
            MoveRight();
            break;
        case KEY_LEFT:
            MoveLeft();
            break;
        case KEY_UP:
            RotateBlock();
            break;
        case KEY_R:
            Reset();
            break;
        default:
            break;
    }
}    



void Game::MoveDown()
{
    if(!GameOver)
    {    Currentblock.Move(1, 0);
        if(IsBlockOutside() || BlockFits() == false)
        {
            Currentblock.Move(-1, 0);
            LockBlock();
        }
    }
}

void Game::MoveLeft()
{
    if(!GameOver){
        Currentblock.Move(0, -1);
        if(IsBlockOutside() || BlockFits() == false)
        {
            Currentblock.Move(0, 1);
        }
    }
}

void Game::MoveRight()
{
    if(!GameOver){
        Currentblock.Move(0, 1);
        if(IsBlockOutside() || BlockFits() == false)
        {
            Currentblock.Move(0, -1);
        }
    }
}

void Game::RotateBlock()
{
    if(!GameOver){
    Currentblock.Rotate();
    if(IsBlockOutside() || BlockFits() == false)
    {
        Currentblock.undoRotation();
    }
    }
}


bool Game::IsBlockOutside()
{
    std::vector<position> block = Currentblock.GetCellPosition();

    for(auto item : block )
    {
        if(grid.IsCellOutside(item.x, item.y))
        { 
            return true;
        }
    }

    return false;
}

void Game::LockBlock()
{
    std::vector<position> tiles = Currentblock.GetCellPosition();
    for (auto item : tiles)
    {
        grid.grid[item.x][item.y] = Currentblock.id;
    }

    Currentblock = NextBlock;
    if(BlockFits() == false)
    {
        GameOver = true;
    }

    NextBlock = GetRandomBlock(); 
    int completed = grid.ClearFullRows();
    updateScore(completed, 0);
}

bool Game::BlockFits(){
    std::vector<position> tiles = Currentblock.GetCellPosition();

    for (auto item : tiles)
    {
        if(grid.IsCellEmpty(item.x, item.y) == false)
        {
            return false;
        }
        
    }

    return true;
}

void Game::Reset()
{
    grid.initialize();
    Blocks = GetAllBlocks();
    Currentblock = GetRandomBlock();
    NextBlock = GetRandomBlock();
}

void Game::updateScore(int completed, int moved)
{
    switch (completed)
    {
    case 1:
        Score += 100;
        break;
    case 2:
        Score += 300;
        break;
    case 3:
        Score += 500; 
    default:
        break;
    }

    Score += moved;

}


