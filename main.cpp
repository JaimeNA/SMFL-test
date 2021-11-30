#include"Game.h"
#include"Player.h"

int main()
{
    
    Game game("Game",800, 800);

    Player player(20, 20, game.createTexture("t.png"));

    // run the program as long as the window is open
    while (game.getWindowShouldClose())
    {
        
        game.Update(&player);

        game.Render(player.getSprite());

    }

    return 0;
}   