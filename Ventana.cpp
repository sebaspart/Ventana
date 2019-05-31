
#include "juego.hpp"
int main()
{
   juego game(800,600,"Pepito");
   game.addFigure(0);
   game.addImage(1);

   game.gameloop();

    return 0;
}
