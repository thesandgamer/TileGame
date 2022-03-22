#include "raylib.h"
#include <iostream>
#include <stdio.h>  
#include <math.h> 
#include <vector>
#include <string>

#include "Grid.h"
#include "Pawn.h"
#include "AStar.h"

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
Pawn pawn;

void Start()
{
    const static int GRID_WIDTH = 10;
    const static int GRID_HEIGHT = 10;

    const static int CELL_WIDTH = 32;
    const static int CELL_HEIGHT = 32;

    grid = Grid(GRID_WIDTH, GRID_HEIGHT, CELL_WIDTH, CELL_HEIGHT);
    pawn = Pawn({5,5}, 20, 20);
    pawn.gridRef = &grid;
}

void Update()
{
    Vector2 mousePos = GetMousePosition();
    Vector2 mousePosInGrid = grid.PosInGrid(mousePos);
   // cout << mousePosInGrid.x << " " << mousePosInGrid.y << endl;
    pawn.Update();
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
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        if (grid.IsInGrid(mousePosInGrid))
        {
            pawn.MoveTo(Vector2AStar(mousePosInGrid.x, mousePosInGrid.y));
            grid.grid[mousePosInGrid.x][mousePosInGrid.y].goal = true;

        }
    }

}

void Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    grid.Draw();
    pawn.Draw();

    DrawUi();
    EndDrawing();
}

void DrawUi()
{

}