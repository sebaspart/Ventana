#include "juego.hpp"

juego::juego(){
    window.create(sf::VideoMode(800,600),"Nada",sf::Style::Close);
    window.setVerticalSyncEnabled(true); //freeSinc

}

juego::juego(int ressx,int ressy,std::string name){
    window.create(sf::VideoMode(ressx,ressy,32),name,sf::Style::Close);
    window.setVerticalSyncEnabled(true); //freeSinc
    window.setFramerateLimit(60);

}

void juego::gameloop(){
    while(window.isOpen()){

        eventos();
        drawing();


    }


}

void juego::eventos(){
    sf::Vector2i Position= sf::Mouse::getPosition(window);
        while(window.pollEvent(event))
        {


            switch(event.type)
            {     //window closed
                case sf::Event::Closed:
                window.close();
                break;
                //if(event.mouseButton.button==sf::Mouse::Left){

                //}

                break;
                case sf::Event::KeyPressed:
                    if(event.key.code==sf::Keyboard::X){
                        addFigure(figuras[0].im_type,figuras[0].get_state(),figuras[0].get_position());

                    }
                    if(event.key.code==sf::Keyboard::M){
                        size_t i=0;
                        while(i<figuras.size()){
                        figuras[i].change_state('n');
                        i++;
                        }
                    }
                    if(event.key.code==sf::Keyboard::A){
                        size_t i=0;
                        while(i<figuras.size()){
                        figuras[i].change_state('d');
                        i++;
                        }

                    }
                    break;
                default:
                break;
            }
        }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
                    figuras[0].move_position(Position);
              }

              if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                figuras[figuras.size()-1].move_position(Position);

              }

            //indicador de coordenadas al click izquierdo
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                if( figuras[0].inside(localPosition)){
                    std::cout<<"Esta dentro"<<std::endl;
                }
                else{
                    std::cout<<"Esta fuera"<<std::endl;
                }
            }

}

void juego::coppyFig(){
    help.resize(figuras.size());
    size_t i=0;
    while(i<figuras.size()){
        help[i].coppy(figuras[i].im_type,figuras[i].get_state(),figuras[i].get_position());
        i++;
    }
    i=0;
    figuras.resize(figuras.size()+1);
     while(i<help.size()){
        figuras[i].coppy(help[i].im_type,help[i].get_state(),help[i].get_position());
        i++;
    }
}
void juego::coppyIm(){
    help.resize(imagenes.size());
    size_t i=0;
    while(i<figuras.size()){
        help[i].coppy(imagenes[i].im_type,imagenes[i].get_state(),imagenes[i].get_position());
        i++;
    }
    i=0;
    imagenes.resize(imagenes.size()+1);
     while(i<help.size()){
        imagenes[i].coppy(help[i].im_type,help[i].get_state(),help[i].get_position());
        i++;
    }

}

void juego::addFigure(int name){
    if(figuras.size()) coppyFig();
    else figuras.resize(1);
    figuras[figuras.size()-1].asignation(name);
}

void juego::addImage(int name){

    if(imagenes.size()) coppyIm();
    else imagenes.resize(1);
    imagenes[imagenes.size()-1].asignation(name);
}

void juego::addFigure(int type,char new_state,sf::Vector2f possition){
    if(figuras.size()) coppyFig();
    else figuras.resize(1);
    figuras[figuras.size()-1].coppy(type,new_state,possition);
}
void juego::addImage(int type,char new_state,sf::Vector2f possition){
    if(imagenes.size()) coppyIm();
    else imagenes.resize(1);
    imagenes[imagenes.size()-1].coppy(type,new_state,possition);
}

void juego::drawing(){
    window.clear();
    size_t i=0;
    while(i<imagenes.size()){
        window.draw(imagenes[i].sprite());
        i++;
    }
    i=0;
    while(i<figuras.size()){
        window.draw(figuras[i].sprite());
        i++;
    }
    window.display();
}
