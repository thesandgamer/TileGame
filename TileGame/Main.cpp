#include "raylib.h"
#include <iostream>
#include <stdio.h>  
#include <math.h> 
#include <vector>
#include <string>

#include "Grid.h"

using namespace std;

//Editor Variable
void Update();
void Draw();
void DrawUi();
void Start();

//Setup la taille de l'écran
int const SCREEN_WIDTH = 960;
int const SCREEN_HEIGHT = 540;

int main(int argc, char* argv[])
{

    //Créer un écran et on met les fps à 60
    string windowName = "TileGame";
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowName.c_str());

    //ToggleFullscreen();
    SetWindowPosition(0, 10);
    SetTargetFPS(60);

    Start();

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        Update();
        // Draw
        Draw();       

    }

    CloseWindow();

    return 0;


}

Grid grid;

void Start()
{

    grid = Grid(10, 10,32,32);

}

void Update()
{

}

void Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    grid.Draw();

    DrawUi();
    EndDrawing();
}

void DrawUi()
{

}