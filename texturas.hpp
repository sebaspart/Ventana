#ifndef TEXTURAS_HPP
#define TEXTURAS_HPP
#include "Im.hpp"
#include <SFML/Graphics.hpp>
class figura{
public:

    figura();

    //Constructor
    figura(int name);



    sf::Vector2f get_position();

    //Movimiento del objeto
    void move_position(sf::Vector2f destino);

    void move_position(sf::Vector2i destino);

    void move_offset(float x, float y);

    //Estado 'd'    Daño
    //Estado 'w'    Caminar
    //Estado 'm'    Muerto
    //Estado 'h'    Curacion
    void change_state(char new_state);

    void asignation(int name);

    //Deteccion dentro de area de una figura
    int inside(sf::Vector2i medicion);

    sf::Sprite sprite();

    void set_scale(float fact);

    //Funciones de copia
    void coppy(int type,char new_sate,sf::Vector2f possition);
    char get_state();
    int im_type;



    private:
        //Animacion daño
    void damage_im();

        //Cambio de sprite a mostrar
    void change_im();

        //Reloj para animacion
    sf::Clock damage_clk;

        //Posicion referencia para animacion
    sf::Vector2f main_poss;

        //Valor referencia para animacion
    int anim_on;

    //condicion de animacion
    int damage_true;

    //imagen actual a seleccionar del arreglo
    int current_im;

    void change_color();

    char state;

     //arreglo de sprites para animaciones u otros usos

    Im objeto[2];
};

#endif // TEXTURAS_HPP
