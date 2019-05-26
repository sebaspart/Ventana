#include "Im.hpp"

    Im::Im(){
        asignation(0,0);
        inicial=Base.getColor();
    }

    //tipo de objeto e indice de imagen del objeto
    Im::Im(int type, int index){
        asignation(type,index);


        inicial=Base.getColor(); //color de referencia inicial
    }

    void Im::recolor(const char indicador){
        //modificar color base del sprite
        switch (indicador)
        {
            //verde heal
            case 'h':
                Base.setColor(sf::Color(0,255,0));

            break;
            //gris muerto
            case 'g':
                Base.setColor(sf::Color(130,130,130));

            break;
            //rojo daño
            case 'r':
                Base.setColor(sf::Color(255,0,0));

            break;
            //else
            default:
                Base.setColor(inicial); //regreso al color inicial
             break;


        }

    }
    void Im::position_set(sf::Vector2f position){
        Base.setPosition(position);

    }
    sf::Vector2f Im::position_get(){
        return Base.getPosition();

    }
    int Im::asignation(int type, int index){
    if(type ==0){
            //imagen raiz
             if(!Imagen.loadFromFile("morg.JPG")){
            return -1;
            }
            switch (index){
            case 0:
                //caso 1 de figura
                Base.setTexture(Imagen);
                Base.setTextureRect(sf::IntRect(0,0,64,64));
                {sf::Vector2f centro;
                centro.x=Base.getTextureRect().width/2.f;
                centro.y=Base.getTextureRect().height/2.f;
                Base.setOrigin(centro);
                }
                break;

            }

    }


    return 0;
    }
