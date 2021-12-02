#include"Game.h"

void Game::initWindow(const char* Name){

    this->window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT), Name);
    this->window.setVerticalSyncEnabled(true);//synchronizes with the vertical frequency of the monitor

}

Game::Game(const char* Name, const int width, const int height)
: WIN_WIDTH(width), WIN_HEIGHT(height){//Initializer

    this->initWindow(Name);

}

Texture Game::createTexture(const char* dir){

    Texture tex;

    if(!tex.loadFromFile(dir)){

        std::cout << "Error loading texture from file" << std::endl;

    }

    return tex;

}

void Game::UpdateInput(RectangleShape* sprite){

    switch (this->event.key.code){

    case Keyboard::Escape:
        
        this->window.close();

    break;
    
    case Keyboard::A:

        sprite->move(Vector2f(-5.f, 0.f));

    break;

    case Keyboard::D:

        sprite->move(Vector2f(5.f, 0.f)); 

    break;

    case Keyboard::W:

        sprite->move(Vector2f(0.f, -5.f));

    break;

    case Keyboard::S:

        sprite->move(Vector2f(0.f, 5.f));

    break;
  
    default:
    break;
    }


}

void Game::Update(RectangleShape* sprite){

    // check all the window's events that were triggered since the last iteration of the loop
    
    while (this->window.pollEvent(this->event)){
    
        UpdateInput(sprite);

    }

}

void Game::Render(RectangleShape* sprite){

    // clearing the window with a white color
    window.clear(Color::White);

    if (!renderTexture.create(WIN_WIDTH, WIN_HEIGHT)){

    // error
    std::cout << "Failed to create render texture::Game.cpp" << std::endl;

    }

    // OFF-SCREEN drawing 

    // clear the textures
    renderTexture.clear();

    renderTexture.draw(*sprite);

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