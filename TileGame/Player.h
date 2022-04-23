#pragma once
#include "raylib.h"
#include <vector>
using std::vector;

#include "Button.h"
#include "Pawn.h"


class Player: public ITurn
{
public:
	Player();
	~Player();

	void Start();
	void Update();
	void Draw();
	void DrawUi();

	void MovePawn();

	bool SelectPawn();
	void DeSelectPawn();

	vector<Pawn>* GetPawns();

	void SetGrid(class Grid* grid);

	Vector2 GetMousePosInGrid() { return mousePosInGrid; }

	void FinishPlayerTurn();





//==========Interfaces==========
	void StartTurn();
	bool EndTurn();
	int initiative;
	bool finishHisTurn = false;

private:
	vector<Pawn> pawns;
	Pawn* controledPawn;

	class Grid* gridRef;

//==========
	Vector2 mousePos;
	Vector2 mousePosInGrid;

//==========
	bool isTurn = false;

	Player* This;

//==========UI==========
	Button* endTurnButton = nullptr;




};

//C'est la classe qui va servir � g�rer le joueur
//On va y stoquer les pawn qu'il poss�de
//On va stoquer le pawn qu'on contr�le actu�lement	


//On va aussi y stoquer son Ui