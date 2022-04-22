#pragma once
#include <iostream> 
#include "raylib.h"
#include "easings.h"

#include "Grid.h"
#include "Vector2AStar.h"
#include "InformationDisplay.h"
#include "IInformationPasseur.h"
#include "ITurn.h"




class Pawn: public IInformationPasseur
{
public:
	Pawn();
	Pawn(Vector2 positionP);
	Pawn(Vector2 positionP,float widthP,float heightP);
	~Pawn();

	void Init();
	void Draw();
	void Update();
		
	Vector2 position;

	float width;
	float height;

	void MoveTo(Vector2 positionToGo);

	InformationDisplay* GetInformations() { return informations; }

	string GetInformationOf() override;

	Grid* gridRef;

	Pawn(const Pawn& other)
	{
		operator=(other);
	}

	Pawn& operator=(const Pawn& other)
	{
		this->position = other.position;
		this->width = other.width;
		this->height = other.height;	
		this->gridRef = other.gridRef;
		this->informations = other.informations;
		return *this;
	}


	bool selected = false;


private:
	InformationDisplay* informations;

	bool canMove = false;
	
	bool haveDoActions = false;	



};

