#include<raylib.h>
#include<iostream>
#include "game.h"
#include "colors.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >=  interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }

    return false;
}



int main()
{
    InitWindow(580, 680, "tetris");
    SetTargetFPS(60);
    Game game = Game();
    
    Font font = LoadFont("font/Minecraft.ttf");


    while(WindowShouldClose() == false)
    {   
        if(EventTriggered(0.2))
        {
            game.MoveDown();
        }

        game.HandleInput();
        
        BeginDrawing();

        DrawTextEx(font, "Tetris", {37, 8}, 30, 2, WHITE);
        DrawTextEx(font, "Score", {380, 8}, 30, 2, WHITE);

        char scoretext[10];
        sprintf(scoretext, "%d", game.Score);
        DrawTextEx(font, scoretext, {380, 35}, 30, 2, WHITE);
        DrawTextEx(font, "Made By Tanush Gupta", {30, 650}, 30, 2, WHITE);
        DrawTextEx(font, "Next", {380, 225}, 30, 2, WHITE);
        DrawRectangleRounded({368, 260, 180, 200}, 0.1f, 2, Next);
        


        ClearBackground(BG);
        game.Draw();
        if(game.GameOver)
        {
            DrawRectangleRounded({60, 60, 400, 550}, 0.1f, 2, GO);
            DrawTextEx(font, "Game Over!", {140, 310}, 40, 2, WHITE);
        }
        EndDrawing();
    } 

    CloseWindow();

}