#include"Snake.h"

Snake::Snake(){

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

        player[i]->setPosition(20.f * i + 100.f, 100.f);
        
    }

    for(int i = 0; i < player.size();i++){

        PosX[i] = player[i]->getPosition().x;
        PosY[i] = player[i]->getPosition().y;

    }

}

void Snake::Move(float x, float y){

if(!this->dead){

    for(int i = 1; i < player.size();i++){ // setting the positon of the previous block

        player[i]->setPosition(PosX[i-1], PosY[i-1]);

    }

    player[0]->move(Vector2f(x, y)); // moving the head

    for(int i = 0; i < player.size();i++){

        PosX[i] = player[i]->getPosition().x;
        PosY[i] = player[i]->getPosition().y;

    }
}   

}

bool Snake::Colision(RenderWindow* window){

    // wall colision

    if(PosX[0] < -20.f){ // if it collides with a wall

        player[0]->setPosition(window->getSize().x, PosY[0]);

    }else if(PosY[0] < -20.f){

        player[0]->setPosition(PosX[0], window->getSize().y);

    }else if(PosX[0] > window->getSize().x){

        player[0]->setPosition(-10.f, PosY[0]);

    }else if(PosY[0] > window->getSize().y){

        player[0]->setPosition(PosX[0], -10.f);

    }

    // body colision

    for(int i = 5;i < player.size();i++){ 

        if(abs(PosX[0] - PosX[i]) < 5.f && abs(PosY[0] - PosY[i]) < 5.f){

            player[i]->setFillColor(Color(250, 100, 50));

            this->Move(0.f, 0.f);

            this->dead = true; // so its stop moving 

            return true;

        }

    }

    return false;

}

void Snake::InSize(){ // increasing the size by one
        
    this->player.push_back(new RectangleShape); 

    this->player[this->player.size() - 1]->setSize(Vector2f(20, 20));

}