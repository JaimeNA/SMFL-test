#pragma once

#include"Libraries.h"

class Food{

private:

    RectangleShape food;

public:

    // contructor   

    Food(){

        food.setSize(Vector2f(10.f, 10.f));

    }

    // functions

    void Gen(RenderWindow* window){

        food.setPosition(rand() % window->getSize().x, rand() % window->getSize().y);// getting a random position to generate the food

    }

    // accessors

    float GetX(){ return food.getPosition().x; }
    float GetY(){ return food.getPosition().y; }

    RectangleShape* GetFood(){ return &this->food; }
};
