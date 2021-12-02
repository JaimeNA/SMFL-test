#include"Cube.h"

Cube::Cube(const int CUBE_WIDTH, const int CUBE_HEIGHT, Texture CUBE_TEX){

    this->cube.setSize(Vector2f(CUBE_WIDTH, CUBE_HEIGHT));
    this->cube.setTexture(&CUBE_TEX);

}