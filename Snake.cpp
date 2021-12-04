#include"Snake.h"

Snake::Snake(){

    this->cube.push_back(new Cube(20, 20));
    this->cube.push_back(new Cube(20, 20));
}

void Snake::Update(Game* game){

    game->Update(cube[0]->getSprite());


}
