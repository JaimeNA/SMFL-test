#include"Game.h"
#include"Snake.h"
#include"Food.h"

int main()
{
    
    Game game("Game",800, 800);// creating game object 

    Snake snake;

    Food food;

    // run the program as long as the window is open
    while (game.getWindowShouldClose())
    {

        game.Update(&snake, &food);  
        game.Render(snake.GetSnake(), &food);
            
    }

    return 0;
}   