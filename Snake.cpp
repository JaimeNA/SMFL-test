#include"Snake.h"

Snake::Snake(){

    this->cube.push_back(new RectangleShape);
    this->cube.push_back(new RectangleShape);

    cube[0]->setSize(Vector2f(20, 20));
}

void Snake::Update(Game* game){

    game->Update(cube);

}

void Snake::Move(float x, float y){

}