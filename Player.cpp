#include"Player.h"

Player::Player(const int PLAYER_WIDTH, const int PLAYER_HEIGHT, Texture PLAYER_TEX){

    this->player.setSize(Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
    this->player.setTexture(&PLAYER_TEX);

}