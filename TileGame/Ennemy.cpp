#include "Ennemy.h"

Ennemy::Ennemy()
{
}

Ennemy::~Ennemy()
{
}

void Ennemy::Start()
{
	pawns.push_back(Pawn({ 7,0 }, 15, 15));
	pawns.push_back(Pawn({ 4,2 }, 15, 15));

	for (int i = 0; i < pawns.size(); i++)
	{
		pawns.at(i).col = PURPLE;
		pawns.at(i).selCol = DARKPURPLE;
		pawns.at(i).Init();
	}
}

void Ennemy::Update()
{
	//==========Update les pawns============
	for (int i = 0; i < pawns.size(); i++)
	{
		pawns.at(i).Update();
	}
}

void Ennemy::Draw()
{
	//=========Draw les pawns============
	for (int i = 0; i < pawns.size(); i++)
	{
		pawns.at(i).Draw();
	}
}

vector<Pawn>* Ennemy::GetPawns()
{
	return &pawns;
}

void Ennemy::SetGrid(Grid* grid)
{
	gridRef = grid;
}

void Ennemy::FinishEnnemyTurn()
{
	finishHisTurn = true;
}

void Ennemy::StartTurn()
{
	std::cout << "Its Ennemy Turn " << std::endl;
	for (Pawn& pawn : pawns)
	{
		pawn.haveDoActions = false;
	}
	isTurn = true;
	finishHisTurn = false;
}

bool Ennemy::EndTurn()
{
	return finishHisTurn;
}
