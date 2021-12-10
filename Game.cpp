#include"Game.h"

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

void Game::UpdateInput(Snake* snake){

    static float x, y = 15.f;

    // check all the window's events that were triggered since the last iteration of the loop
    
    if (this->window.pollEvent(this->event)){

        switch (this->event.key.code){

        case Keyboard::Escape:
        
            this->window.close();

        break;
    
        case Keyboard::A:// left

            if(x == 0.f) // block going back in the same direction
                x = -15.f;  

            y = 0.f;

        break;

        case Keyboard::D:// right
        
            if(x == 0.f)
                x = 15.f; // to avoid going diagonal
            y = 0.f;

        break;

        case Keyboard::W:// up

            x = 0.f;

            if(y == 0.f)
                y = -15.f;

        break;

        case Keyboard::S:// down

            x = 0.f;

            if(y == 0.f)
            y = 15.f;

        break;

        case Keyboard::Space:// down

            snake->InSize();
            

        break;
  
        default:
        break;
        }

    }

    if(!snake->Colision(&window)){// checking for collision

        snake->Move(x, y);// moving the snake in requested direction

    }

}

void Game::Update(Snake* snake){

    UpdateInput(snake);

}

Texture Tex;

void Game::Render(std::vector<RectangleShape*> cube){

    cube[0]->setTexture(createTexture("t.png"));

    // clearing the window with a white color
    window.clear(Color::White);

    // OFF-SCREEN drawing 

    // clear the textures
    renderTexture.clear();

    for(int i = 0; i < cube.size();i++){// go through all the elements

        renderTexture.draw(*cube[i]);

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