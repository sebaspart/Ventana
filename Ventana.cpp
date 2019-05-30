
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "texturas.hpp"
int main()
{
    figura knigth(13);
    figura cuadro(7);
    figura rombo(8);
    figura cleric(9);
    figura rogue(10);
    figura female(11);
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
                      //rombo.move_position(Position);

                    }
                    if(event.mouseButton.button==sf::Mouse::Left){
                       //cuadro.move_position(Position);
                    }

                  break;
                     //reescalado de la pantalla y cambio de coordenadas internas  *no completo*
                  case sf::Event::Resized:
                        window.setView(sf::View(sf::FloatRect (0.f,0.f,event.size.width,event.size.height)));

                  case sf::Event::KeyPressed:
                        if(event.key.code==sf::Keyboard::M){
                rombo.change_state('d');
                cuadro.change_state('d');
                knigth.change_state('d');
                cleric.change_state('d');
                rogue.change_state('d');
                female.change_state('d');
                        }

                  default:
                    break;
              }
              }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)){
                rombo.change_state('h');
                cuadro.change_state('h');
                knigth.change_state('h');
                cleric.change_state('h');
                rogue.change_state('h');
                female.change_state('h');
              }
              if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
                rombo.change_state('n');
                cuadro.change_state('n');
                knigth.change_state('n');
                cleric.change_state('n');
                rogue.change_state('n');
                female.change_state('n');
              }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                cuadro.move_position(Position);
              }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                knigth.move_position(Position);
              }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                rombo.move_position(Position);
              }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
                cleric.move_position(Position);
              }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)){
                rogue.move_position(Position);
              }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
                female.move_position(Position);
              }

                /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
                rombo.change_state('d');
                cuadro.change_state('d');
                knigth.change_state('d');
                i= cleric.change_state('d');
                rogue.change_state('d');
                female.change_state('d');
              }  */

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)){
                 rombo.change_state('m');
                cuadro.change_state('m');
                knigth.change_state('m');
                cleric.change_state('m');
                rogue.change_state('m');
                female.change_state('m');
              }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
                 rombo.change_state('w');
                cuadro.change_state('w');
                knigth.change_state('w');
                cleric.change_state('w');
                rogue.change_state('w');
                female.change_state('w');
              }


             window.clear(sf::Color(180,200,255));


            window.draw(cuadro.sprite());
            window.draw(rombo.sprite());
            window.draw(knigth.sprite());
            window.draw(cleric.sprite());
            window.draw(rogue.sprite());
            window.draw(female.sprite());
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
