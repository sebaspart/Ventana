
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "texturas.hpp"
int main()
{
    float i=1.f;
    figura cuadro(0);
    figura rombo(1);
    sf::RenderWindow window(sf::VideoMode(800,630,32),"Juego",sf::Style::Close);
    window.setVerticalSyncEnabled(true); //freeSinc
     //loop de ventana
        while(window.isOpen())
        {
            sf::Vector2i Position= sf::Mouse::getPosition(window);
            sf::Event event;
            while(window.pollEvent(event))
            {


              switch(event.type)
              {     //window closed
                  case sf::Event::Closed:
                    window.close();
                    break;
                  case sf::Event::MouseButtonPressed:
                    if(event.mouseButton.button==sf::Mouse::Right){
                      rombo.move_position(Position);

                    }
                    if(event.mouseButton.button==sf::Mouse::Left){
                       //cuadro.move_position(Position);
                    }

                  break;
                     //reescalado de la pantalla y cambio de coordenadas internas  *no completo*
                  case sf::Event::Resized:
                        window.setView(sf::View(sf::FloatRect (0.f,0.f,event.size.width,event.size.height)));

                  default:
                    break;
              }
              }
              window.clear(sf::Color(180,200,255));
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                rombo.change_state('h');
              }
              if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
                rombo.change_state('n');
              }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                cuadro.move_position(Position);
              }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
                cuadro.set_scale(i+=0.5);
              }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)){
                cuadro.set_scale(i-=0.5);
              }
            window.draw(cuadro.sprite());
            window.draw(rombo.sprite());
            window.display();

                //indicador de coordenadas al click izquierdo
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                if( cuadro.inside(localPosition)){
                    std::cout<<"Esta dentro"<<std::endl;
                }
                else{
                    std::cout<<"Esta fuera"<<std::endl;
                }
            }
        }

    return 0;
}
