#include "Player.h"
#include "Grid.h"

Player::Player(): controledPawn{nullptr}, gridRef{nullptr}, mousePos{},mousePosInGrid{}
{
}

Player::~Player()
{
}

void Player::Start()
{

//=========G�re les pawns
	pawns.push_back(Pawn({5,5},20,20));
	pawns.push_back(Pawn({8,8},20,20));
	//controledPawn = &pawns.at(0);

	for (int i = 0; i < pawns.size(); i++)
	{
		pawns.at(i).Init();
	}

//==========UI============
	endTurnButton = new Button({ 10,10 }, 40.0f, 40.0f);
	endTurnButton->textInButton = "End Turn";
	endTurnButton->functPrt = &FinishPlayerTurn;





}

void Player::Update()
{
	if (!isTurn) return;
	mousePos = GetMousePosition();
	mousePosInGrid = gridRef->PosInGrid(mousePos);

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (controledPawn == nullptr)
		{
			SelectPawn();
		}
		else
		{
			if (!SelectPawn())
			{
				MovePawn();
			}

		}
	}
	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
	{
		DeSelectPawn();
	}

//==========Update les pawns============
	for (int i = 0; i < pawns.size(); i++)
	{
		pawns.at(i).Update();
	}
}

void Player::Draw()
{
//=========Draw les pawns============
	for (int i = 0; i < pawns.size(); i++)
	{
		pawns.at(i).Draw();
	}
}

void Player::DrawUi()
{
	endTurnButton->Update();
	endTurnButton->Draw();

}



void Player::MovePawn()
{
	if (gridRef->IsInGrid(mousePosInGrid))
	{
		if (gridRef->grid[mousePosInGrid.x][mousePosInGrid.y].traversible == true)
		{
			std::cout << "traversible" << std::endl;
			controledPawn->MoveTo({ mousePosInGrid.x, mousePosInGrid.y });
			gridRef->grid[mousePosInGrid.x][mousePosInGrid.y].goal = true;
		}

	}
}

bool Player::SelectPawn()
{
	if (gridRef->IsInGrid(mousePosInGrid))
	{
		std::cout << "Pawn ref: " << &pawns[0] << std::endl;
		std::cout << "Pawn ref: " << &pawns[1] << std::endl;

		for (Pawn& pawn : pawns)
		{
			if (pawn.position.x == mousePosInGrid.x && pawn.position.y == mousePosInGrid.y)
			{
				std::cout << "Pawn controlled: " << &pawn << std::endl;
				if (controledPawn != nullptr) DeSelectPawn();
				controledPawn = &pawn;
				pawn.selected = true;
				return true;
			}

		}
		//Aucun n'a �t� trouv� � cette case
		return false;

	}
}

void Player::DeSelectPawn()
{
	controledPawn->selected = false;
	controledPawn = nullptr;
}

vector<Pawn>* Player::GetPawns()
{
	return &pawns;
}

void Player::SetGrid(Grid* grid)
{
	gridRef = grid;
}

void Player::FinishPlayerTurn()
{
	finishHisTurn = true;
}

void Player::StartTurn()
{
	std::cout << "Its player Turn " << std::endl;
	isTurn = true;
}

bool Player::EndTurn()
{
	return finishHisTurn;
}
