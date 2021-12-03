#include"Snake.h"

Snake::Snake(){

    cube.push_back(new Cube(20, 20));

}

void Snake::Update(Game* game){

    game->Update(cube[0]->getSprite());

    game->Render(cube[0]->getSprite());

}//Dejo el commit para maniana