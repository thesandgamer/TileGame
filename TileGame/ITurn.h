#pragma once

class ITurn
{
public:
	virtual void StartTurn() = 0;
	virtual bool EndTurn() = 0;

	int initiative;
	bool finishHisTurn;

	//Peut être string name pour que le manager puisse afficher qui joue
};