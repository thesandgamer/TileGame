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

//=========Gère les pawns
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
	//endTurnButton->functPrt = [this]() { finishHisTurn = true } ();
	endTurnButton->setCallback( [this]() { this->FinishPlayerTurn(); } );//Set la fonction de callback créer un fonction lambda
							//Quel objet // Quel fonction


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
			//std::cout << "traversible" << std::endl;
			controledPawn->MoveTo({ mousePosInGrid.x, mousePosInGrid.y });
		}

	}
}

bool Player::SelectPawn()
{
	if (gridRef->IsInGrid(mousePosInGrid))
	{

		for (Pawn& pawn : pawns)
		{
			if (pawn.position.x == mousePosInGrid.x && pawn.position.y == mousePosInGrid.y)
			{
				//std::cout << "Pawn controlled: " << &pawn << std::endl;
				if (controledPawn != nullptr) DeSelectPawn();
				controledPawn = &pawn;
				pawn.selected = true;
				return true;
			}

		}
		//Aucun n'a été trouvé à cette case
		return false;

	}
}

void Player::DeSelectPawn()
{
	if (controledPawn != nullptr)
	{
		controledPawn->selected = false;
		controledPawn = nullptr;
	}	
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
	isTurn = false;
	finishHisTurn = true;

	endTurnButton->isActive = false;
}



void Player::StartTurn()
{
	std::cout << "Its player Turn " << std::endl;
	for (Pawn& pawn : pawns)
	{
		pawn.haveDoActions = false;
	}
	isTurn = true;
	finishHisTurn = false;

	endTurnButton->isActive = true;

}

bool Player::EndTurn()
{
	return finishHisTurn;
}
