#include "Game.h"

void Game::SetupScreen(int screenwidth, int screenHeight)
{
    SCREEN_WIDTH = screenwidth;
    SCREEN_HEIGHT = screenHeight;
}

void Game::Start()
{
//===========Setup la Grille==============
    const static int GRID_WIDTH = 10;
    const static int GRID_HEIGHT = 10;

    const static int CELL_WIDTH = 32;
    const static int CELL_HEIGHT = 32;
    Vector2 gridPos = { SCREEN_WIDTH / 2 - (GRID_WIDTH * CELL_WIDTH) / 2 ,SCREEN_HEIGHT / 2 - (GRID_HEIGHT * CELL_HEIGHT) / 2 };

    grid = Grid(gridPos, GRID_WIDTH, GRID_HEIGHT, CELL_WIDTH, CELL_HEIGHT);
    grid.Start();


//=============Setup Player============
	player.Start();
    player.SetGrid(&grid);

//=============Setup Ennemly============
    ennemy.Start();
    ennemy.SetGrid(&grid);

//=============
    cursor.Start();

//============Setup elements in game==============
    for (int i = 0; i < player.GetPawns()->size(); i++)
    {
        elementsInGame.push_back(&player.GetPawns()->at(i));
    }
    for (int i = 0; i < ennemy.GetPawns()->size(); i++)
    {
        elementsInGame.push_back(&ennemy.GetPawns()->at(i));
    }

//===========Setup les info==========
    infoUi = new InformationDisplayUi();
    infoUi->SetPosition({ (float)SCREEN_WIDTH - SCREEN_WIDTH / 3,0 });

    //Get les info des pawns du player
    for (int i = 0; i < player.GetPawns()->size(); i++)
    {
        informations.push_back(player.GetPawns()->at(i).GetInformations());
    }
    //Get les info des pawns de l'ennemi
    for (int i = 0; i < player.GetPawns()->size(); i++)
    {
        informations.push_back(ennemy.GetPawns()->at(i).GetInformations());
    }

    //On va parcourir toutes les tiles de la grille et r�cup�rer les informaion pour les mettre dans informations
    for (int i = 0; i < grid.grid.size(); i++)
    {
        for (int j = 0; j < grid.grid[i].size(); j++)
        {
            informations.push_back(grid.grid[i][j].GetInformations());
        }
    }

//=========Setup Turn Manager===========
    turnManager.AddPawn(&player);
    turnManager.AddPawn(&ennemy);
    turnManager.Start();




}

void Game::Update()
{
    turnManager.Update();
    grid.Update();
	player.Update();
    ennemy.Update();
    cursor.Updtate();


//=======Updtate infos=========
    for (InformationDisplay* inf : informations)
    {
        if (inf->GetPos().x == player.GetMousePosInGrid().x && inf->GetPos().y == player.GetMousePosInGrid().y)
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
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    grid.Draw();
	player.Draw();
    ennemy.Draw();

    DrawUi();

    EndDrawing();
}

void Game::DrawUi()
{
	player.DrawUi();
    cursor.Draw();

//=======Draw les infos========
    infoUi->Draw();
}
