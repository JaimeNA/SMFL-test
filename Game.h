#pragma once

#include"Libraries.h"

class Game{
    
    private:

        RenderWindow window;
        Event event;
        RenderTexture renderTexture;
        Sprite tempSprite;

        const int WIN_WIDTH, WIN_HEIGHT;

        void initWindow(const char* Name);

    public:

        //Constructor

        Game(const char* Name, const int width, const int height);

        //Accessors

        bool getWindowShouldClose(){ return window.isOpen(); }

        //Functions

        Texture createTexture(const char* dir);
        void UpdateInput(RectangleShape* sprite);
        void Update(RectangleShape* sprite);
        void Render(RectangleShape* sprite);
};