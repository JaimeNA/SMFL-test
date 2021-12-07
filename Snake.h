#pragma once

#include"Libraries.h"

class Snake{

private:

    static float PosX, PosY;

    std::vector<RectangleShape*> player;

public:

    // contructor

    Snake();

    // functions

    void Update();
    void Move(float x, float y);
    bool Colision();

    // accessors

	void SetX(float X) { PosX += X; }
	void SetY(float Y) { PosY += Y; }

	double GetX() { return PosX; }
	double GetY() { return PosY; }
    std::vector<RectangleShape*> GetSnake(){ return player; }

};

