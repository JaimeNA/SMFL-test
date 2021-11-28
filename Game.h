#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>

#include<iostream>
#include<vector>

using namespace sf;

class Game{
    
    private:

        RenderWindow window;
        Event event;
        RenderTexture renderTexture;
        Sprite tempSprite, mainSprite;
        // textures

        std::vector<Texture*> texture;

        const int WIN_WIDTH, WIN_HEIGHT;

        void initWindow(const char* Name);
        void initTexture(short tex, const char* dir);

    public:

        //Constructor

        Game(const char* Name, const int width, const int height);

        //Accessors

        bool getWindowShouldClose(){ return window.isOpen(); }

        //Functions

        void UpdateInput();
        void Update();
        void Render();
};