#include"Game.h"
#include"Cube.h"

int main()
{
    
    Game game("Game",800, 800);

    Cube cube(20, 20, game.createTexture("t.png"));

    // run the program as long as the window is open
    while (game.getWindowShouldClose())
    {
        
        game.Update(cube.getSprite());

        game.Render(cube.getSprite());

    }

    return 0;
}   