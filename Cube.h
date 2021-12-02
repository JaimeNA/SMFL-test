#pragma once

#include"Libraries.h"

class Cube{

private:

    static float PosX, PosY;
    int lenght;
    RectangleShape cube;

public:

    // contructor

    Cube(const int CUBE_WIDTH, const int CUBE_HEIGHT, Texture CUBE_TEX);

    // functions

    void Update();
    RectangleShape* getSprite(){ return &this->cube; }
    bool Colision();

    // accessors

	void SetX(float X) { PosX += X; }
	void SetY(float Y) { PosY += Y; }

	double GetX() { return PosX; }
	double GetY() { return PosY; }

};

