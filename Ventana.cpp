
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{

    sf::RenderWindow window(sf::VideoMode(800,630,32),"Juego",sf::Style::Close);
    window.setVerticalSyncEnabled(true); //freeSinc
    //acondicionamiento de textura
    sf::Texture textura;
    if(!textura.loadFromFile("morg.JPG")){
        return -1;
    }
    //sprite's correspondientes con centro adecuado
    sf::Sprite sprite;
    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0,0,64,64));
    sprite.move(50,100);
    {sf::Vector2f centro;
    centro.x=sprite.getTextureRect().width/2.f;
    centro.y=sprite.getTextureRect().height/2.f;
    sprite.setOrigin(centro);
    }
    sprite.rotate(45);

    sf::Sprite otro(textura);
    otro.setPosition(200,150);
    otro.setTextureRect(sf::IntRect(128,128,64,64));
    {sf::Vector2f centro;
    centro.x=otro.getTextureRect().width/2.f;
    centro.y=otro.getTextureRect().height/2.f;
    otro.setOrigin(centro);
    }
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
                  //key pressed
                  case sf::Event::KeyPressed:
                        //rotacion de sprite otro
                        otro.rotate(45);
                     break;
                  case sf::Event::MouseButtonPressed:
                    if(event.mouseButton.button==sf::Mouse::Right){
                      otro.setPosition(Position.x,Position.y);

                    }
                    if(event.mouseButton.button==sf::Mouse::Left){
                       sprite.setPosition(Position.x,Position.y);
                    }

                  break;
                     //reescalado de la pantalla y cambio de coordenadas internas
                  case sf::Event::Resized:
                        window.setView(sf::View(sf::FloatRect (0.f,0.f,event.size.width,event.size.height)));

                  default:
                    break;
              }
              }
              window.clear(sf::Color(180,200,255));

            window.draw(sprite);
            window.draw(otro);
            window.display();

                //indicador de coordenadas al click izquierdo
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                std::cout<<localPosition.x<<"    " ;
                std::cout<<localPosition.y<<std::endl;
            }
        }

    return 0;
}
