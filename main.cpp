#include <SFML/Graphics.hpp>
#include"Game.h"

int main()
{
    
    Game game("Game",800, 800);

    // run the program as long as the window is open
    while (game.getWindowShouldClose())
    {
        
        game.Update();

    }

    return 0;
}