#ifndef JUEGO_HPP
#define JUEGO_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "texturas.hpp"
#include <iostream>

class juego{
	public:
    juego();
    juego(int ressx,int ressy,std::string name);
    void gameloop();
    void drawing();
    void eventos();
    void addFigure(int name);
    void addImage(int name);
    void addFigure(int type,char new_state,sf::Vector2f possition);
    void addImage(int type,char new_state,sf::Vector2f possition);


	private:
    void coppyIm();
    void coppyFig();
    sf::RenderWindow window;
    std::vector <figura> figuras;
    std::vector <figura> help;
    std::vector <figura> imagenes;
    sf::Event event;
    sf::Clock delay;

};




#endif // JUEGO_HPP
