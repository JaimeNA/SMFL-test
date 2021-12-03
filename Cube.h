#pragma once

#include"Libraries.h"

class Cube{

private:

    static float PosX, PosY;
    int lenght;
    RectangleShape cube;

public:

    // contructor

    Cube(const int CUBE_WIDTH, const int CUBE_HEIGHT){

        this->cube.setSize(Vector2f(CUBE_WIDTH, CUBE_HEIGHT));

    }

    // functions

    void Update();
    RectangleShape* getSprite(){ return &this->cube; }

    // accessors

	void SetX(float X) { PosX += X; }
	void SetY(float Y) { PosY += Y; }
    void setTex(Texture* CUBE_TEX){ this->cube.setTexture(CUBE_TEX); }

	double GetX() { return PosX; }
	double GetY() { return PosY; }

};

