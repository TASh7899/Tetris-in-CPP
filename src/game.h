#include "grid.h"
#include "blocks.cpp"
#include <vector>

class Game{
    public:
        Game();
        Grid grid;
        void Draw();
        void HandleInput();
        void MoveDown();
        int Score;
        bool GameOver;
    private:
        std::vector<Block> Blocks;
        std::vector<Block> GetAllBlocks();
        Block GetRandomBlock();
        Block Currentblock;
        Block NextBlock;
        void updateScore(int completed, int  moved);
        void MoveLeft();
        void MoveRight();
        bool IsBlockOutside();
        void LockBlock();
        void RotateBlock();
        bool BlockFits();
        void Reset();
        
};