#include"Game.h"
#include"Cube.h"
#include"Snake.h"

int main()
{
    
    Game game("Game",800, 800);// creating game object 

    Snake snake;

    // run the program as long as the window is open
    while (game.getWindowShouldClose())
    {
        
       snake.Update(&game);

    }

    return 0;
}   