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
    void start();
    void personajes_select();

	private:
	  int hit(std::vector<figura> comparar);
	  void fight();
    //Dibujado en pantalla de todos los elementos
     void drawing();
	 void drawing(sf::Text);
	 void drawing(sf::Sprite Fondo, sf::Sprite Cabecera);
	 void eventos();
	//Funciones para vector de ayuda
    void coppyIm();
    void coppyFig();
    void coppyPer();
    void coppydat(std::vector<figura> copia);
    //Agregado de elementos al vector
    //Funciones personales debido a un error dentro de la libreria SFML y el uso de la plantilla Vector
    void addFigure(int name);
    void addImage(int name);
    void addPersonaje(int name);
    void add(int name, std::vector<figura> destino);
    void add(int type,char new_state,sf::Vector2f possition,std::vector<figura> destino);
    void addFigure(int type,char new_state,sf::Vector2f possition);
    void addImage(int type,char new_state,sf::Vector2f possition);
    int compare(std::vector<figura> comparar );
    int compare(figura comp);
    void move_map(sf::Sprite &mapa,int ancho);
    sf::RenderWindow window;
    int action;
    std::vector <figura> figuras;
    std::vector <figura> personajes;
    std::vector <figura> help;
    std::vector <figura> imagenes;
    sf::Event event;
    int battle_init;
    void generate_enemies(int type,int amount);
    int stage;
};




#endif // JUEGO_HPP
