#include "juego.hpp"

juego::juego(){
    window.create(sf::VideoMode(800,600),"Nada",sf::Style::Close);
    window.setVerticalSyncEnabled(true); //freeSinc

}

juego::juego(int ressx,int ressy,std::string name){
    window.create(sf::VideoMode(ressx,ressy,32),name);
    window.setVerticalSyncEnabled(true); //freeSinc
    window.setFramerateLimit(60);

}

void juego::gameloop(){
    while(window.isOpen()){

        eventos();
        drawing();


    }


}
void juego::personajes_select(){
    size_t i=0;
    size_t fig=0;
    while(fig<6){
                addFigure(fig);
                fig+=1;
            }
    addImage(16); //fondo
    addImage(17); //cartel
            figuras[0].move_position(sf::Vector2f(233,261));
            figuras[1].move_position(sf::Vector2f(420,261));
            figuras[2].move_position(sf::Vector2f(627,261));
            figuras[3].move_position(sf::Vector2f(233,492));
            figuras[4].move_position(sf::Vector2f(420,492));
            figuras[5].move_position(sf::Vector2f(627,492));
        int aux=-1;
        std::vector<int> a;
        a.resize(3);
        while(i<3){
            a[i]=-1;
            i+=1;
        }
        i=0;
    while(window.isOpen()&&i<3){
        eventos();
        aux=compare(figuras);
           if(aux!=-1&&a[0]!=aux&&a[1]!=aux&&a[2]!=aux){
               a[i]=aux;
                figuras[aux].change_state('w');

                i+=1;
           }

        drawing();
    }
    i=0;
    while(i<3){
            std::cout<<a[i]<<std::endl;
            if(a[i]<0){

            }
            else{
            std::cout<<"entre"<<std::endl;
             addPersonaje(a[i]);

            }

        i+=1;
    }

    figuras.clear();
    imagenes.clear();
}

int juego::compare(std::vector<figura> comparar){
    size_t i=0;

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    while (i<comparar.size()){
        if( comparar[i].inside(localPosition)){
                return comparar[i].im_type;
            }

        i+=1;
    }
    }
    return -1;
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
                //if( figuras[0].inside(localPosition)){
                    std::cout<<"Coordenada x: "<<localPosition.x<<std::endl<<"Coordenada y: "<<localPosition.y<<std::endl;
                //}
                //else{
                    //std::cout<<"Esta fuera"<<std::endl;
                //}
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

void juego::coppyPer(){
    help.resize(imagenes.size());
    size_t i=0;
    while(i<personajes.size()){
        help[i].coppy(personajes[i].im_type,personajes[i].get_state(),personajes[i].get_position());
        i++;
    }
    i=0;
    personajes.resize(imagenes.size()+1);
     while(i<help.size()){
        personajes[i].coppy(help[i].im_type,help[i].get_state(),help[i].get_position());
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
void juego::addPersonaje(int name){

    if(personajes.size()) coppyPer();
    else personajes.resize(1);
    personajes[personajes.size()-1].asignation(name);
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
    i=0;
    while(i<personajes.size()){
        window.draw(personajes[i].sprite());
        i++;
    }
    window.display();
}
