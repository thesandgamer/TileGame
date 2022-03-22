#include "Pawn.h"


Pawn::Pawn()
{
	position = { -1, -1 };
	x = -1;
	y = -1;
	gridRef = new Grid();

}

Pawn::Pawn(Vector2 positionP)
{
	position.x = positionP.x;
	position.y = positionP.y;
	x = positionP.x;
	y = positionP.y;
	//gridRef = new Grid();

}

Pawn::Pawn(Vector2 positionP, float widthP, float heightP)
{
	position.x = positionP.x;
	position.y = positionP.y;
	x = positionP.x;
	y = positionP.y;
	width = widthP;
	height = heightP;
	//gridRef = new Grid();


}

Pawn::~Pawn()
{
}

bool canMove;
std::vector<Vector2AStar> poses;

void Pawn::Draw()
{

	DrawRectangle( position.x * gridRef->CELL_WIDTH + width/4 , position.y * gridRef->CELL_HEIGHT + height/4 ,width,height,YELLOW);
}

void Pawn::Update()
{
	/*
	if (canMove)
	{
		int i = 0;
		Vector2AStar posToGo = poses[i];
		if (i >= poses.size())
		{
			canMove = false;
			return;
		}
		if (position == posToGo)
		{
			i++;
		}
		position.x += 0.1f;
		position.y += 0.1f;
		q
		int duration = 40;
		int currentTime = 0;

		for (Vector2AStar posToGo : poses)
		{
			while (position != posToGo)
			{
				position.x = EaseSineIn(currentTime, position.x, posToGo.x - position.x, duration);
				position.y = EaseSineIn(currentTime, position.y, posToGo.y - position.y, duration);
				currentTime++;

			}
		}
	}*/
}


void Pawn::MoveTo(Vector2AStar positionToGo)
{
	//Si il n'y a pas de position � aller, finit
	//Appel le A star
	//std::vector<Vector2AStar> poses = gridRef->aStar.GetPath(position,positionToGo);
	gridRef->Debug_CleanPathVisibility();
	poses = gridRef->aStar.GetPath(position,positionToGo);
	canMove = true;

	Vector2AStar actualPos = position;
	float currentTime = 0;
	int duration = 400000;

	/*
	while (position != positionToGo)
	{
		position.x += 0.1; //EaseSineIn(currentTime, actualPos.x, positionToGo.x - actualPos.x, duration);
		position.y += 0.1; //EaseSineIn(currentTime, actualPos.y, positionToGo.y - actualPos.y, duration);
		//currentTime++;

	}
	*/
	for (Vector2AStar posToGo : poses)
	{
		gridRef->grid[posToGo.x][posToGo.y].goal = true;
		//x = posToGo.x;
		//y = posToGo.y;<
		std::cout << posToGo.x << " " << posToGo.y << std::endl;

		/*
		Vector2AStar actualPos = position;
		float currentTime = 0;
		while (position != posToGo)
		{
			position.x = EaseSineIn(currentTime, actualPos.x, posToGo.x - actualPos.x, 100);
			position.y = EaseSineIn(currentTime, actualPos.y, posToGo.y - actualPos.y, 100);
			currentTime++;

		}*/
		/*
		int currentTime = 0;
		int duration = 400;
		Vector2AStar startPosition = position;
		while (position.x > posToGo.x && position.y > posToGo.y)
		{
			//position.x = EaseSineIn(currentTime, startPosition.x, posToGo.x - startPosition.x, duration);
			//position.x += 0.1;
			//position.y += 0.1;
			//position.y = EaseSineIn(currentTime, startPosition.y, posToGo.y - startPosition.y, duration);
			std::cout <<"Position: " << position.x << " " << position.y << std::endl;

			currentTime++;
		}
		std::cout << "finish move" << std::endl;


		int currentTime = 0;
		int duration = 40000;
		float startPositionX = 0.0f;
		float finalPositionX = 30.0f;
		float currentPositionX = startPositionX;

		while (currentPositionX < finalPositionX)
		{
			//currentPositionX = EaseSineIn(currentTime, startPositionX, finalPositionX - startPositionX, duration);
			currentPositionX += 0.1f;
			//std::cout << currentPositionX << std::endl;
			currentTime++;
		}
		std::cout << "FINISH" << std::endl;
		x = posToGo.x;
		y = posToGo.y;

		*/
	}

	//On va r�cup�rer les positions donn�es par le A* et les parcourir
		//On va faire un lerp entre la position actuel et la position 
	//On va attendre un peut
	//Et on continue la boucle

}
