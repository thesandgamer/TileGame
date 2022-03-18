#include "Pawn.h"

Pawn::Pawn()
{
	position = { -1, -1 };
	x = -1;
	y = -1;

}

Pawn::Pawn(Vector2 positionP)
{
	position = positionP;
	x = positionP.x;
	y = positionP.y;
}

Pawn::Pawn(Vector2 positionP, float widthP, float heightP)
{
	position = positionP;
	x = positionP.x;
	y = positionP.y;
	width = widthP;
	height = heightP;

}

Pawn::~Pawn()
{
}

void Pawn::Draw()
{
	DrawRectangle(x , y,width,height,YELLOW);
}

void Pawn::MoveTo(Vector2 positionToGo)
{
	//Appel le A star
	//On va récupérer les positions données par le A* et les parcourir
		//On va faire un lerp entre la position actuel et la position 
	//On va attendre un peut
	//Et on continue la boucle
}
