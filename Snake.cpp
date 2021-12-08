#include"Snake.h"

Snake::Snake(){

    this->player.push_back(new RectangleShape);
    this->player.push_back(new RectangleShape);
    this->player.push_back(new RectangleShape);
    this->player.push_back(new RectangleShape);
    this->player.push_back(new RectangleShape);
    this->player.push_back(new RectangleShape);
    this->player.push_back(new RectangleShape);
    this->player.push_back(new RectangleShape);
    // setting size

    for(int i = 0; i < player.size();i++){

        player[i]->setSize(Vector2f(20, 20));

    }

    // setting starting positions
    
    for(int i = 0; i < player.size();i++){

        player[i]->setPosition(20.f * i, 0);
        
    }

    for(int i = 0; i < player.size();i++){

        PosX[i] = player[i]->getPosition().x;
        PosY[i] = player[i]->getPosition().y;

    }

}

    float tempX, tempY, tempX1, tempY1;

void Snake::Move(float x, float y){

    for(int i = 1; i < player.size();i++){ // setting the positon of the previous block

        player[i]->setPosition(PosX[i-1], PosY[i-1]);

    }

    player[0]->move(Vector2f(x, y)); // moving the head

    for(int i = 0; i < player.size();i++){

        PosX[i] = player[i]->getPosition().x;
        PosY[i] = player[i]->getPosition().y;

    }
}

void Snake::Colision(RenderWindow* window){

    if(PosX[0] < 0.f){ // if it collides with a wall

        PosX[0] = window->getSize().x;

    }else if(PosX[0] > window->getSize().x){

        this->SetX(0.f);

    }else if(PosY[0] < 0.f - 20.f * player.size()){ // if it collides with a wall

        this->SetY(window->getSize().y);

    }else if(PosY[0] > window->getSize().y){

        this->SetY(0.f);

    }

}

void Snake::SetX(float x){

    for(int i = 0; i < player.size();i++){ // change all objects position

        player[i]->setPosition(i * 20.f + x, PosY[i]);

    }

}

void Snake::SetY(float y){

    for(int i = 0; i < player.size();i++){ // change all objects position

        player[i]->setPosition(PosX[i], i * 20.f + y);

    }

}