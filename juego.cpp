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
    personajes[0].move_position(sf::Vector2f(30,30));
    personajes[1].move_position(sf::Vector2f(120,30));
    personajes[2].move_position(sf::Vector2f(210,30));
    while(window.isOpen()){

        eventos();
        drawing();


    }
}

void juego::start(){
    //CREACION DE LA FUENTE
	sf::Font fuente;
	sf::Text texto;
	//CARGAMOS LA FUENTE TTF (ESTILO DE FUENTE)
	fuente.loadFromFile("Imagenes/fuente1.ttf");
	//ELEGIMOS EL ESTILO DE FUENTE
	texto.setFont(fuente);
	//DAMOS NOMBRE AL JUEGO
	texto.setString("Ancient Dungeon");
	texto.setPosition(250,50);
	texto.setScale(1.f,2.f);
	addImage(18);
	addImage(19);
	addImage(20);
	int i=1;
	int aux;
	while(window.isOpen()&&i){
        eventos();
        aux=compare(imagenes);
        if(aux==19)i=0;
        if(aux==20)window.close();


        drawing(texto);

	}
	imagenes.clear();
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
            if(a[i]<0){

            }
            else{
             addPersonaje(a[i]);

            }

        i+=1;
    }

    figuras.clear();
    imagenes.clear();
}

int juego::compare(std::vector<figura> comparar){
    size_t i=comparar.size();

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    while (i>0){
        if( comparar[i-1].inside(localPosition)){
                return comparar[i-1].im_type;
            }

        i-=1;
    }
    }
    return -1;
}
int juego::compare(figura comparar){

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);

        if( comparar.inside(localPosition)){
                return comparar.im_type;
            }


    }
    return -1;
}

void juego::eventos(){
   // sf::Vector2i Position= sf::Mouse::getPosition(window);
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
                        while(i<personajes.size()){
                        personajes[i].change_state('n');
                        i++;
                        }
                    }
                    if(event.key.code==sf::Keyboard::A){
                        size_t i=0;
                        while(i<personajes.size()){
                        personajes[i].change_state('d');
                        i++;
                        }

                    }
                    break;
                default:
                break;
            }
        }
                //if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
                    //imagenes[0].move_position(Position);
              //}

              //if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
               // figuras[figuras.size()-1].move_position(Position);

              //}
              //if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
               // std::cout<<"Coordenada x: "<<Position.x<<std::endl;
               // std::cout<<"Coordenada y: "<<Position.y<<std::endl;
              //}
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
    while(i<imagenes.size()){
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
    help.resize(personajes.size());
    size_t i=0;
    while(i<personajes.size()){
        help[i].coppy(personajes[i].im_type,personajes[i].get_state(),personajes[i].get_position());
        i++;
    }
    i=0;
    personajes.resize(personajes.size()+1);
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
void juego::drawing(sf::Text Texto){
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
    window.draw(Texto);
    while(i<personajes.size()){
        window.draw(personajes[i].sprite());
        i++;
    }
    window.display();

}
