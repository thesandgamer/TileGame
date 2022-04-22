#include "TurnsManager.h"

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
	haveTurn = pawns.at(0);
	MakeTurns();
}

void TurnsManager::Update()
{
	if (haveTurn != nullptr) //Si quelqu'un existe
	{
		if (haveTurn->EndTurn())//Si il à finit son tour
		{
			//Passe au suivant
			if (actual < pawns.size())
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
	haveTurn = pawns.at(actual);
	haveTurn->finishHisTurn = false;
	haveTurn->StartTurn();

}

void TurnsManager::AddPawn(ITurn* turn)
{
	pawns.push_back(turn);
}
