#include "BandeauTexte.h"

BandeauTexte::BandeauTexte()
{
}

BandeauTexte::BandeauTexte(Texture2D spriteP, Vector2 positionP, float lifeTimeP) : sprite{ spriteP }, position{ positionP },lifeTime{lifeTimeP}, isActive(false)
{
}

BandeauTexte::~BandeauTexte()
{
}

float currentTime;

void BandeauTexte::Update()
{
	if (!isActive) return;
	if (currentTime <= lifeTime)
	{
		currentTime += GetFrameTime();
	}
	else
	{
		isActive = false;
	}

}

void BandeauTexte::Draw()
{
	if (!isActive) return;
	if (sprite.width != NULL)
	{
		DrawTexture(sprite, position.x, position.y, WHITE);
		string text = textIn + " Turn";
		DrawText(text.c_str(), sprite.width / 2 - MeasureText(text.c_str(),30)/2, position.y +sprite.height / 2 - 14, 30, WHITE);
	}
}

void BandeauTexte::DisplayBandeau()
{
	isActive = true;
	currentTime = 0;

}

void BandeauTexte::SetText(string text)
{
	std::cout <<"New text: " << text << std::endl;
	textIn = text;
}


