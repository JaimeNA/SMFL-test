#pragma once

#include"Libraries.h"

class Snake{

private:

    float PosX[20], PosY[20];

    std::vector<RectangleShape*> player;

public:

    // contructor

    Snake();

    // functions

    void Update();
    void Move(float x, float y);
    void Colision(RenderWindow* window);

    // accessors

    void SetX(float x);
    void SetY(float y);
    std::vector<RectangleShape*> GetSnake(){ return player; }

};

