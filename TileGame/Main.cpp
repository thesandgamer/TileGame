#include "raylib.h"
#include <iostream>
#include <stdio.h>  
#include <math.h> 
#include <vector>
#include <string>
#include <map>

#include "Grid.h"
#include "Pawn.h"
#include "AStar.h"
#include "Button.h"

#include "InformationDisplayUi.h"

using namespace std;

//Editor Variable
void Update();
void Draw();
void DrawUi();
void Start();

//Setup la taille de l'écran
int const SCREEN_WIDTH = 960;
int const SCREEN_HEIGHT = 540;

Grid grid;
Pawn pawn;

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
        DrawUi();

    }

    CloseWindow();

    return 0;


}

Button* endTurnButton;
InformationDisplayUi* infoUi;
//map<Vector2*,InformationDisplay*> informations;
vector<InformationDisplay*> informations;

void Start()
{
    const static int GRID_WIDTH = 10;
    const static int GRID_HEIGHT = 10;

    const static int CELL_WIDTH = 32;
    const static int CELL_HEIGHT = 32;
    Vector2 gridPos = { SCREEN_WIDTH / 2 - (GRID_WIDTH * CELL_WIDTH)/2 ,SCREEN_HEIGHT / 2 - (GRID_HEIGHT * CELL_HEIGHT )/2 };

    grid = Grid(gridPos,GRID_WIDTH, GRID_HEIGHT, CELL_WIDTH, CELL_HEIGHT);
    grid.Start();

    pawn = Pawn({5,5}, 20, 20);
    pawn.gridRef = &grid;
    pawn.Init();

    endTurnButton = new Button({10,10}, 40.0f, 40.0f);
    endTurnButton->textInButton = "End Turn";

    infoUi = new InformationDisplayUi();
    infoUi->SetPosition({ SCREEN_WIDTH- SCREEN_WIDTH/3,0 });

    //informations.insert({ &pawn.position,pawn.GetInformations() });
    informations.push_back(pawn.GetInformations());

    //On va parcourir toutes les tiles de la grille et récupérer les informaion pour les mettre dans informations
    for (int i = 0; i < grid.grid.size(); i++)
    {
        for (int j = 0; j < grid.grid[i].size(); j++)
        {
            informations.push_back(grid.grid[i][j].GetInformations());
        }
    }


}

void Update()
{
    Vector2 mousePos = GetMousePosition();
    Vector2 mousePosInGrid = grid.PosInGrid(mousePos);
   // cout << mousePosInGrid.x << " " << mousePosInGrid.y << endl;
    pawn.Update();
    grid.IsInGrid(mousePosInGrid);
    /*   ======== Remove/replace Tiles ===========
    * 
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
    }*/

   
    //On va récupérer ce qu'il y a en dessous de la souris, tile, pawn, ennemi,...: tout ce qui possède l'infomationDisplay
    //On va passer l'information display du truc pointé dans l'ui inforamtion display

    for (InformationDisplay* inf : informations)
    {
        if (inf->GetPos().x == mousePosInGrid.x && inf->GetPos().y == mousePosInGrid.y)
        {
            //Quand on est sur l'info display, faire en sorte d'appeler la fonction pour setup le texte
            inf->infPasseur->GetInformationOf();
            infoUi->infoLinkedTo = inf;
            break;
        }
        else
        {
            infoUi->infoLinkedTo = nullptr;
        }
    }
    // infoUi->infoLinkedTo = pawn.GetInformations();


    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        if (grid.IsInGrid(mousePosInGrid) )
        {
            if (grid.grid[mousePosInGrid.x][mousePosInGrid.y].traversible == true)
            {
                std::cout << "traversible" << std::endl;
                pawn.MoveTo({ mousePosInGrid.x, mousePosInGrid.y });
                grid.grid[mousePosInGrid.x][mousePosInGrid.y].goal = true;
            }

        }
    }
    
    endTurnButton->Update();


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
    endTurnButton->Draw();
    infoUi->Draw();


}