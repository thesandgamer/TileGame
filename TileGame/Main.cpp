#include "raylib.h"
#include <iostream>
#include <stdio.h>  
#include <math.h> 
#include <vector>
#include <string>
#include <map>

#include "Game.h"

using namespace std;

//Editor Variable
void Update();

//Setup la taille de l'écran
int const SCREEN_WIDTH = 960;
int const SCREEN_HEIGHT = 540;


int main(int argc, char** argv[])
{

    //Créer un écran et on met les fps à 60
    string windowName = "TileGame";
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowName.c_str());

    //ToggleFullscreen();
    SetWindowPosition(0, 10);
    SetTargetFPS(60);
    Game::instance().SetupScreen(SCREEN_WIDTH, SCREEN_HEIGHT);


    Game::instance().Start();

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        Game::instance().Update();    
        Game::instance().Draw();
    }

    CloseWindow();

    return 0;


}



void Update()
{
    /*
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        
        if (grid.IsInGrid(mousePosInGrid))
        {          
            if (grid.grid[mousePosInGrid.x][mousePosInGrid.y].traversible)
            {
                grid.grid[mousePosInGrid.x][mousePosInGrid.y].traversible = false;
                grid.aStar.aStarGrid.AddObstacle({ mousePosInGrid.x,mousePosInGrid.y });
            }
            else
            {
                grid.grid[mousePosInGrid.x][mousePosInGrid.y].traversible = true;
                grid.aStar.aStarGrid.RemoveObstacle({ mousePosInGrid.x,mousePosInGrid.y });
            }
        }
    }
    */

    Button* endTurnButton;
    // UI
    endTurnButton = new Button({ 10,10 }, 40.0f, 40.0f);
    endTurnButton->textInButton = "End Turn";

    endTurnButton->Update();
    endTurnButton->Draw();



}
