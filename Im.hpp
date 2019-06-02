#ifndef IM_HPP
#define IM_HPP
#include <SFML/Graphics.hpp>
class Im{
public:
    Im();
    Im(int type, int index); //tipo de objeto e indice de imagen del objeto

    //recolor de sprite
    // 'r' color rojo
    //'h' como color verde
    //'g' como color gris

    void recolor(const char indicador);

    void position_set(sf::Vector2f position);

    void position_set(sf::Vector2i position);

    //Movimiento a partir de la posicion actual
    void position_move(float x, float y);

    void set_scale(float fact);

    sf::Vector2f position_get();

    //Asignasion de imagen
    // type=0   Caballero
    // type=1   Mago
    // type=2   Cazador
    // type=3   Clerigo
    // type=4   Picaro
    // type=5   Mujer
    // type=6   Cyclope
    // type=7   Fantasma
    // type=8   Diablillo
    // type=9   Caballero Oscuro
    // type=10  Mago Oscuro
    // type=11  Cosa Huevo
    // type=12  Mounstro del Pantano
    // type=13  Abeja
    // type=14  Recuadro Atacar
    // type=15  Recuadro Curar
    // type=16  Fondo seleccion de personajes
    // type=17  Leyenda seleccion personajes
    // type=18  Fondo pantalla inicio
    // type=19  Recuadro Iniciar
    // type=20  Recuadro Salir
    int asignation(int type, int index);

    sf::Sprite draw();

    sf::Vector2f rect();

    private:
    sf::Sprite Base;
    sf::Texture Imagen[2];
    sf::Color inicial;
    float factor;
};


#endif // IM_HPP
