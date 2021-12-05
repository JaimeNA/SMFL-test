#include"Game.h"

#include"Snake.h"

void Game::initWindow(const char* Name){

    this->window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT), Name);
    this->window.setVerticalSyncEnabled(true);//synchronizes with the vertical frequency of the monitor

}

Game::Game(const char* Name, const int width, const int height)
: WIN_WIDTH(width), WIN_HEIGHT(height){//Initializer

    this->initWindow(Name);


    if (!this->renderTexture.create(WIN_WIDTH, WIN_HEIGHT)){

        // error
        std::cout << "Failed to create render texture::Game.cpp" << std::endl;

    }


}

Texture* Game::createTexture(const char* dir){

    if(!this->tex.loadFromFile(dir)){// chicking for errors

        std::cout << "Error loading texture from file" << std::endl;

    }

    return &this->tex;

}

void Game::UpdateInput(std::vector<Cube*> cube){

    switch (this->event.key.code){

    case Keyboard::Escape:
        
        this->window.close();

    break;
    /*
    case Keyboard::A:// left

        sprite->move(Vector2f(-5.f, 0.f));

    break;

    case Keyboard::D:// right

        cube[0]->getSprite().move(Vector2f(5.f, 0.f)); 

    break;

    case Keyboard::W:// up

        sprite->move(Vector2f(0.f, -5.f));

    break;

    case Keyboard::S:// down

        sprite->move(Vector2f(0.f, 5.f));

    break;
  */
    default:
    break;
    }


}

void Game::Update(std::vector<Cube*> cube){

    // check all the window's events that were triggered since the last iteration of the loop
    
    while (this->window.pollEvent(this->event)){
    
        UpdateInput(cube);

    }

}

Texture Tex;

void Game::Render(std::vector<Cube*> cube){

    // clearing the window with a white color
    window.clear(Color::White);

    // OFF-SCREEN drawing 

    // clear the textures
    renderTexture.clear();

    for(int i = 0; i < cube.size();i++){// go through all the elements

        renderTexture.draw(*cube[i]->getSprite());

    }

    // end the current frame
    renderTexture.display();

    // ON-SCREEN drawing 

    // get the target texture (where the stuff has been drawn)
    Tex = renderTexture.getTexture();

    tempSprite.setTexture(Tex);

    // draw it on the window 
    window.draw(tempSprite);

    // end the current frame
    window.display();

}