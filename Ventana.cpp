
#include "juego.hpp"
int main()
{
   juego game(800,600,"Ancient Dungeon");
    game.start();
    game.personajes_select();
   game.gameloop();

    return 0;
}
