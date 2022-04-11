#include "Button.h"
Button::Button()
{
}

Button::Button(Vector2 pos, Texture2D spriteP, float widthP, float heightP):position(pos), sprite(spriteP), width(widthP), height(heightP), state(ButtonState::IDLE), functPrt(nullptr), functPrtInt(nullptr)
{
	drawColor = WHITE;
	mousePos = nullptr;
	value = -1;
}

Button::Button(Vector2 pos, float widthP, float heightP) : position(pos), width(widthP), height(heightP), state(ButtonState::IDLE), functPrt(nullptr), functPrtInt(nullptr)
{
	drawColor = WHITE;
	mousePos = nullptr;
	value = -1;

}

Button::~Button()
{

}

void Button::Update()
{
	mousePos = &GetMousePosition();
	//Check Si la souris est en hover
	if ((position.x < mousePos->x && mousePos->x < position.x + width)
		&& (position.y < mousePos->y && mousePos->y < position.y + height))
	{
		state = ButtonState::HOVER;
		drawColor = DARKGREEN;
	}
	else
	{
		state = ButtonState::IDLE;
		drawColor = GREEN;
	}

	if (state == ButtonState::HOVER)
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			TraceLog(LOG_INFO, " Button cliqued");
			drawColor = GRAY;
			CliquedSendFunction();

			CliquedSendFunctionWithInt();

		}
	}

}

float fontSize = 10;
void Button::Draw()
{
	DrawRectangle(position.x, position.y, width, height, drawColor);
	if (textInButton != "")
	{
		DrawText(textInButton.c_str(), position.x+ width/2 - textInButton.length(), position.y + height/2 , (width + height) /20, WHITE);
	}

}


void Button::CliquedSendFunction()
{
	if (functPrt != nullptr)
	{
		(*functPrt)();
	}
}

void Button::CliquedSendFunctionWithInt()
{
	if (functPrtInt != nullptr)
	{
		if (value != NULL)
		{
			(*functPrtInt)(value);
		}
	}
}

