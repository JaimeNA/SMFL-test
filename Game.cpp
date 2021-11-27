#include "Game.h"

void Game::initWindow(const char* Name){

    this->window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT), Name);
    this->window.setVerticalSyncEnabled(true);//synchronizes with the vertical frequency of the monitor

}
CircleShape shape(50.f);
Game::Game(const char* Name, const int width, const int height)
: WIN_WIDTH(width), WIN_HEIGHT(height){//Initializer

    this->initWindow(Name);
shape.setFillColor(Color(150, 50, 250));

}

void Game::initTexture(short tex, const char* dir){

    if(this->texture.insert().loadFromFile(dir)){// see how i did it with glfw

        std::cout << "Error loading texture from file" << std::endl;

    }

}

void Game::UpdateInput(){

    switch (this->event.key.code){

    case Keyboard::Escape:
        
        this->window.close();

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

    // the rendering loop
    while (window.isOpen())
    {
        // clearing the window with a white color
        window.clear(Color::White);

        this->Render();

        // end the current frame
        window.display();
    }

}

void Game::Render(){

    if (!renderTexture.create(WIN_WIDTH, WIN_HEIGHT)){

    // error
    std::cout << "Failed to create render texture::Game.cpp" << std::endl;

    }

    this->initTexture(0, "t.jpg");
    this->mainSprite.setTexture(texture.at(0));

    // OFF-SCREEN drawing 

    // clear the textures
    renderTexture.clear();

    renderTexture.draw(mainSprite);

    // end the current frame
    renderTexture.display();

    // ON-SCREEN drawing 

    // get the target texture (where the stuff has been drawn)
    const Texture& Texture = renderTexture.getTexture();

    this->tempSprite.setTexture(Texture);
    // draw it on the window 
    window.draw(tempSprite);
}