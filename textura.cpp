#include "texturas.hpp"

    figura::figura(){
            asignation(0);
            //pendiente 24/05/2019 asignar los otros puntos del vector de sprites
    }
    //declaracion de un objeto en la pantalla
    figura::figura(int name){
            asignation(name);
    }
     //coordenadas del objeto
    sf::Vector2f figura::get_position(){
        return objeto[0].position_get();
    }
    //movimiento del objeto
    void figura::move_position(sf::Vector2f destino){
        objeto[0].position_set(destino);
    }

    void figura::move_position(sf::Vector2i destino){
        objeto[0].position_set(destino);
    }
    void figura::change_color(){
        if(state=='h'){ //caminando
            objeto[current_im].recolor('h'); //h= heal= verde
        }
        else if(state=='m'){ //muerto
            objeto[current_im].recolor('g'); //gris
        }
        else if(state=='d'){  //daño
            objeto[current_im].recolor('r'); //rojo
        }
        else{               //vivo o caminando
            objeto[current_im].recolor('n'); //normal
        }

    }
    //indicador de estado para uso de sprite
    void figura::change_state(char new_state){
        state=new_state;
        change_im();
        change_color();

    }

    void figura::set_scale(float fact){
        //aplicar a todos los sprites
        objeto[0].set_scale(fact);
    }

    void figura::change_im(){
        if(state=='w'){ //caminando
            current_im=3;
        }
        else if(state=='m'){ //muerto
            current_im=1;
        }
        else if(state=='d'){  //daño
            current_im=2;
        }
        else{               //vivo o curacion
            current_im=0;
        }


    }
    //cambio de sprite  pendiente asignar el resto de valores del vector al 24/05/19 a las 9:11 pm
    void figura::asignation(int name){
        objeto[0].asignation(name,0);
        current_im=0;
    }
    //regresar sprite a dibujar
    sf::Sprite figura::sprite(){
        return objeto[current_im].draw();
    }
    //Deteccion de si un punto se encuentra dentro de la figura
     int figura::inside(sf::Vector2i medicion){
        sf::Vector2f centro=get_position();
        sf::Vector2f rect=objeto[0].rect();
        float uperBound= centro.y+rect.y;
        float lowerBound= centro.y-rect.y;
        float rightBound= centro.x+rect.x;
        float leftBound= centro.x-rect.x;

        if(uperBound>medicion.y&&lowerBound<medicion.y&&rightBound>medicion.x&&leftBound<medicion.x)  return 1;
        else return 0;

     }
