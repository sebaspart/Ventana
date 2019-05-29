#ifndef TEXTURAS_HPP
#define TEXTURAS_HPP
#include "Im.hpp"
#include <SFML/Graphics.hpp>
class figura{
public:

    figura();
    figura(int name); //declaracion de un objeto en la pantalla
    sf::Vector2f get_position();  //coordenadas del objeto
    void move_position(sf::Vector2f destino);      //movimiento del objeto
    void move_position(sf::Vector2i destino);
    void move_offset(float x, float y);
    int change_state(char new_state); //indicador de estado para uso de sprite
    void asignation(int name);
    int inside(sf::Vector2i medicion);
    sf::Sprite sprite();
    void set_scale(float fact);
    private:
    void change_im();
    int current_im; //imagen actual a seleccionar del arreglo
    int change_color();
    char state;
    Im objeto[2];               //arreglo de sprites para animaciones u otros usos
};

#endif // TEXTURAS_HPP
