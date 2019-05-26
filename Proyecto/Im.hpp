#ifndef IM_HPP
#define IM_HPP
#include <SFML/Graphics.hpp>
class Im{
public:
    Im();
    Im(int type, int index); //tipo de objeto e indice de imagen del objeto
    void recolor(const char indicador);
    void position_set(sf::Vector2f position);
    sf::Vector2f position_get();
    int asignation(int type, int index);
    protected:
    sf::Sprite Base;
    private:
    sf::Texture Imagen;
    sf::Color inicial;
};


#endif // IM_HPP
