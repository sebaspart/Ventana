
#include "juego.hpp"
int main()
{
   juego game(800,600,"Pepito");
   //game.addFigure(17);
   //game.addImage(16);

    game.personajes_select();
   game.gameloop();

    return 0;
}
