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
    void change_state(char new_state); //indicador de estado para uso de sprite
    void asignation(int name);
    int inside(sf::Vector2i medicion);
    sf::Sprite sprite();
    private:
    void change_im();
    int current_im; //imagen actual a seleccionar del arreglo
    void change_color();
    char state;
    protected:
    Im objeto[4];               //arreglo de sprites para animaciones u otros usos
};

#endif // TEXTURAS_HPP
