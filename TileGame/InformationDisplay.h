#pragma once
#include <string>
#include "raylib.h"

using std::string;

class InformationDisplay
{
public:
	InformationDisplay(string titleP);

	string GetTitle() { return title; }

	void SetPos(Vector2* pos) { position = pos; }
	Vector2 GetPos() { return *position; }

private:
	string title;
	Vector2* position;

		
};

//L'id�e va �tre que quand on va passer la souris sur un �l�ment de jeu, �a affiche(� droite en texte pour faire simple) les informations dessus, par exemple on passe la souris sur un ennemi et �a va marquer ce qu'il peut faire,
//ou marquer sa range d'attaque(ou juste la surligner), pareil pour les tiles de base, 

