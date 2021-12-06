#pragma once

#include"Libraries.h"
#include"Game.h"

class Snake{

private:

    static float PosX, PosY;

    std::vector<RectangleShape*> cube;

public:

    // contructor

    Snake();

    // functions

    void Update(Game* game);
    void Move(float x, float y);
    bool Colision();

    // accessors

	void SetX(float X) { PosX += X; }
	void SetY(float Y) { PosY += Y; }

	double GetX() { return PosX; }
	double GetY() { return PosY; }
    std::vector<RectangleShape*> GetSnake(){ return cube; }

};

