#include "Game.h"

void Game::initWindow(const char* Name){

    this->window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT), Name);
    this->window.setVerticalSyncEnabled(true);//synchronizes with the vertical frequency of the monitor

}
CircleShape shape(50.f);
Game::Game(const char* Name, const int width, const int height)
: WIN_WIDTH(width), WIN_HEIGHT(height){//Initializer


    this->initTexture(0, "t.png");
    this->initWindow(Name);

}

void Game::initTexture(short tex, const char* dir){

    this->texture.push_back(new Texture);

    if(!this->texture[0]->loadFromFile(dir)){

        std::cout << "Error loading texture from file" << std::endl;

    }

}

void Game::UpdateInput(){

    switch (this->event.key.code){

    case Keyboard::Escape:
        
        this->window.close();

    break;
    
    case Keyboard::A:

        shape.move(Vector2f(-5.f, 0.f));

    break;

    case Keyboard::D:

        shape.move(Vector2f(5.f, 0.f));

    break;

    case Keyboard::W:

        shape.move(Vector2f(0.f, -5.f));

    break;

    case Keyboard::S:

        shape.move(Vector2f(0.f, 5.f));

    break;

    default:
    break;
    }


}

void Game::Update(){

    // check all the window's events that were triggered since the last iteration of the loop
    
    while (this->window.pollEvent(this->event)){
    
        UpdateInput();

    }

}

void Game::Render(){

    // clearing the window with a white color
    window.clear(Color::White);

    if (!renderTexture.create(WIN_WIDTH, WIN_HEIGHT)){

    // error
    std::cout << "Failed to create render texture::Game.cpp" << std::endl;

    }

    shape.setTexture(texture.at(0));

    // OFF-SCREEN drawing 

    // clear the textures
    renderTexture.clear();

    renderTexture.draw(shape);

    // end the current frame
    renderTexture.display();

    // ON-SCREEN drawing 

    // get the target texture (where the stuff has been drawn)
    const Texture& Tex = renderTexture.getTexture();

    tempSprite.setTexture(Tex);

    // draw it on the window 
    window.draw(tempSprite);

    // end the current frame
    window.display();

}