#include "Tile.h"
#include "Grid.h"

Tile::Tile(): refToGrid{nullptr}, informations{nullptr}
{

}

Tile::Tile(int xP, int yP)
{
	pos.x = xP;
	pos.y = yP;
	traversible = true;
	refToGrid = nullptr;


}

Tile::Tile(int xP, int yP, float widthP, float heightP)
{
	pos.x = xP;
	pos.y = yP;
	width = widthP;
	height = heightP;
	traversible = true;
	refToGrid = nullptr;



}

void Tile::Init()
{
	informations = new InformationDisplay();
	informations->SetPos(&pos);
	informations->infPasseur = this;
}

void Tile::Draw()
{
	Color col = GRAY;
	if (!traversible)
	{
		col = BLACK;
	}
	else if (goal)
	{
		col = PURPLE;
	}
	DrawRectangle(pos.x * width + refToGrid->GetGridPos().x , pos.y * height + refToGrid->GetGridPos().y, width - 4, height - 4, col);
}

string Tile::GetInformationOf()
{
	string info = "Ceci est une tile";
	informations->SetTitle(info);

	return info;
}
