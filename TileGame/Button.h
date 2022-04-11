#pragma once
#include <raylib.h>
#include <string>
#include <iostream>

enum class ButtonState
{
    IDLE, HOVER, CLICK
};

class Button
{
public:
    Button();
    Button(Vector2 pos, Texture2D spriteP, float widthP, float heightP);
    Button(Vector2 pos, float widthP, float heightP);
    ~Button();

    void ButtonCliqued();
    void ButtonHovered();

    void Update();
    void Draw();

    Vector2* mousePos;

    void CliquedSendFunction();
    void CliquedSendFunctionWithInt();

    void (*functPrt)();
    void (*functPrtInt)(int);

    int value;

    std::string textInButton;



private:
    ButtonState state;


    Vector2 position;
    float width;
    float height;
    Texture2D sprite;

    Color drawColor ;

};

