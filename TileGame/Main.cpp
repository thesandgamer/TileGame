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

//Setup la taille de l'�cran
int const SCREEN_WIDTH = 960;
int const SCREEN_HEIGHT = 540;


int main(int argc, char** argv[])
{

    //Cr�er un �cran et on met les fps � 60
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

