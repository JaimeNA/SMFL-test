#include"Snake.h"

Snake::Snake(){

    this->player.push_back(new RectangleShape);
    this->player.push_back(new RectangleShape);
    this->player.push_back(new RectangleShape);
    this->player.push_back(new RectangleShape);

    player[0]->setSize(Vector2f(20, 20));
    player[1]->setSize(Vector2f(20, 20));
    player[2]->setSize(Vector2f(20, 20));
    player[3]->setSize(Vector2f(20, 20));

}

    float tempX, tempY, tempX1, tempY1;

void Snake::Move(float x, float y){

for(int i = 0; i < player.size()-1; i++){

    player[i+1]->setPosition(tempX, tempY);

    tempX = player[i]->getPosition().x;
    tempY = player[i]->getPosition().y;

    player[i]->move(Vector2f(x, y));
    
}

}