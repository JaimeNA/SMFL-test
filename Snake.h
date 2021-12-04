#pragma once

#include"Libraries.h"
#include "Cube.h"
#include"Game.h"

class Snake{

private:

    static float PosX, PosY;

    std::vector<Cube*> cube;

public:

    // contructor

    Snake();

    // functions

    void Update(Game* game);
    bool Colision();

    // accessors

	void SetX(float X) { PosX += X; }
	void SetY(float Y) { PosY += Y; }

	double GetX() { return PosX; }
	double GetY() { return PosY; }
    std::vector<Cube*> GetSnake(){ return cube; }

};

