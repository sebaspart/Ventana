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
    //Dibujado en pantalla de todos los elementos
    void drawing();
    void eventos();
    //Agregado de elementos al vector
    //Funciones personales debido a un error dentro de la libreria SFML y el uso de la plantilla Vector
    void addFigure(int name);
    void addImage(int name);
    void addFigure(int type,char new_state,sf::Vector2f possition);
    void addImage(int type,char new_state,sf::Vector2f possition);


	private:
	//Funciones para vector de ayuda
    void coppyIm();
    void coppyFig();
    sf::RenderWindow window;
    std::vector <figura> figuras;
    std::vector <figura> help;
    std::vector <figura> imagenes;
    sf::Event event;
};




#endif // JUEGO_HPP
