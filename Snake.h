#pragma once

#include"Libraries.h"

class Snake{

private:

    float PosX[200], PosY[200];

    std::vector<RectangleShape*> player;

public:

    // contructor   

    Snake();

    // functions

    void Update();
    void Move(float x, float y);
    bool Colision(RenderWindow* window);

    // accessors

    std::vector<RectangleShape*> GetSnake(){ return player; }

};

