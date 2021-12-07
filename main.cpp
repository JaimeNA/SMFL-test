#include"Game.h"
#include"Snake.h"

int main()
{
    
    Game game("Game",800, 800);// creating game object 

    Snake snake;

    // run the program as long as the window is open
    while (game.getWindowShouldClose())
    {

        game.Update(&snake);  
        game.Render(snake.GetSnake());

    }

    return 0;
}   