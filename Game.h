#pragma once

#include"Libraries.h"

#include"Snake.h"

class Game{
    
    private:

        RenderWindow window;
        Event event;
        RenderTexture renderTexture;
        Sprite tempSprite;
        Texture tex;

        const int WIN_WIDTH, WIN_HEIGHT;

        void initWindow(const char* Name);

    public:

        //Constructor

        Game(const char* Name, const int width, const int height);

        //Accessors

        bool getWindowShouldClose(){ return window.isOpen(); }

        //Functions

        Texture* createTexture(const char* dir);
        void UpdateInput(Snake* snake);
        void Update(Snake* snake);
        void Render(std::vector<RectangleShape*> cube);
};