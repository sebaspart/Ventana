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
    void Im::position_set(sf::Vector2i position){
        Base.setPosition(position.x,position.y);

    }

    sf::Vector2f Im::position_get(){
        return Base.getPosition();

    }

    //Seleccion de sprites para manejo de un personaje u objeto
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
    if(type==1){
        if(!Imagen.loadFromFile("morg.JPG")){
            return -1;
            }
            switch (index){
        case 0:
            Base.setTexture(Imagen);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(128,128,64,64));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }

            }

    }
    return 0;
    }

    sf::Sprite Im::draw(){
        return Base;
    }
