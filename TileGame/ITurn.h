#pragma once
#include <string>
using std::string;


class ITurn
{
public:
	virtual void StartTurn() = 0;
	virtual bool EndTurn() = 0;

	int initiative;
	bool finishHisTurn;

	virtual string GetName() = 0;

	std::string name;

	//Peut �tre string name pour que le manager puisse afficher qui joue
};