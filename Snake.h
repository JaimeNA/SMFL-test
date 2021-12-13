#pragma once

#include"Libraries.h"

#include"Food.h"

class Snake{

private:

    float PosX[200], PosY[200];
    bool dead = false;

    std::vector<RectangleShape*> player;

public:

    // contructor   

    Snake();

    // destructor

    ~Snake(){

        player.clear();

    }

    // functions

    void Update();
    void Move(float x, float y);
    bool Colision(RenderWindow* window, Food* food);

    // accessors

    std::vector<RectangleShape*> GetSnake(){ return player; }
    void InSize();

};

