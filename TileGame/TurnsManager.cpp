#include "TurnsManager.h"
#include "Game.h"

TurnsManager::TurnsManager() : haveTurn{ nullptr }, actual(0)
{
}

TurnsManager::~TurnsManager()
{
}

void TurnsManager::MakeTurnList(vector<ITurn*> pawnInGame)
{
}

void TurnsManager::Start()
{
	Texture2D bandeauSprite = LoadTexture("Ressources/Bandeau.png");
	Vector2 pos = { 0, Game::instance().SCREEN_HEIGHT / 2 };
	endTurnBandeau = BandeauTexte(bandeauSprite,pos,1.5f);
	haveTurn = pawns.at(0);
	MakeTurns();
}

void TurnsManager::Update()
{
	Game::instance().GetGrid()->CalculateObstacles();
	endTurnBandeau.Update();

	if (haveTurn != nullptr) //Si quelqu'un existe
	{
		if (haveTurn->EndTurn())//Si il à finit son tour
		{
			//Passe au suivant
			if (actual < pawns.size()-1)
			{
				actual++;
			}
			else
			{
				actual = 0;
			}
			MakeTurns();
		}
	}
}

void TurnsManager::MakeTurns()
{
	endTurnBandeau.SetText(pawns.at(actual)->GetName());
	endTurnBandeau.DisplayBandeau();

	haveTurn = pawns.at(actual);
	haveTurn->finishHisTurn = false;
	haveTurn->StartTurn();

}

void TurnsManager::DrawUi()
{
	endTurnBandeau.Draw();

}

void TurnsManager::AddPawn(ITurn* turn)
{
	pawns.push_back(turn);
}
