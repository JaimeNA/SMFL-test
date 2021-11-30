#pragma once

#include"Libraries.h"

class Player{

private:

    static float PosX, PosY;
    RectangleShape player;

public:

    // contructor

    Player(const int PLAYER_WIDTH, const int PLAYER_HEIGHT, Texture PLAYER_TEX);

    // functions

    void Update();
    RectangleShape getSprite(){ return this->player; }
    bool Colision();

    // accessors

	void SetX(float X) { PosX += X; }
	void SetY(float Y) { PosY += Y; }
    void move2f(float x, float y){ player.move(Vector2f(x, y)); }

	double GetX() { return PosX; }
	double GetY() { return PosY; }

};

