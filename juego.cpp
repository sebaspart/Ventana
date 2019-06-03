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
    //Inicializaciones  texturas necesarias y valores referencia
    battle_init=0;
    stage=1;
    action=-1;
    addImage(14);
    addImage(15);
    //generate_enemies(6,3);

    sf::Texture t1 ,t2;
	t1.loadFromFile("Imagenes/fondo.png");
	t2.loadFromFile("Imagenes/lateral.jpg");
	sf::Sprite fondo, cabecera;
	fondo.setTexture(t1);
	cabecera.setTexture(t2);
	fondo.setScale(1.42,1.58);
	cabecera.setScale(1.42,0.35);
	int ancho=(int)fondo.getTextureRect().width;

	//posicionamiento de aliados
    personajes[2].move_position(sf::Vector2f(50,542));
    personajes[1].move_position(sf::Vector2f(150,542));
    personajes[0].move_position(sf::Vector2f(250,542));

    while(window.isOpen()){
        /*sf::Vector2i Position= sf::Mouse::getPosition(window);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            std::cout<<"Coordenada x: "<<Position.x<<std::endl;
            std::cout<<"Coordenada y: "<<Position.y<<std::endl;
        }
        */
        move_map(fondo,ancho);

        fight();
         eventos();
        drawing(fondo,cabecera);



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

        aux=compare(imagenes);
        if(aux==19)i=0;
        if(aux==20)window.close();
        eventos();
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
        eventos();
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

int juego::hit(std::vector<figura> comparar){
    size_t i=0;

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);

    while (i<comparar.size()){
        if( comparar[i].inside(localPosition)){
                return (i);
            }

        i+=1;
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
    size_t k=0;
            while(k<personajes.size()){
                if(personajes[k].anim_on||sf::Keyboard::isKeyPressed(sf::Keyboard::D)){

                }
                else{
                    personajes[k].change_state('n');
                }
                k+=1;
            }
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
                        battle_init=1;

                    }
                    if(event.key.code==sf::Keyboard::M){
                        size_t i=0;
                        while(i<personajes.size()){
                        personajes[i].change_state('w');
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
void juego::drawing(sf::Sprite Fondo, sf::Sprite Cabecera){
    window.clear();
    size_t i=0;
    window.draw(Fondo);
    window.draw(Cabecera);
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
void juego::move_map(sf::Sprite &fondo,int ancho){
    size_t i=0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&battle_init<500){
            if((fondo.getPosition().x)*-1 >= ancho/2 + 243 )
        fondo.setPosition(0,0);

			fondo.move(-.7,0);
			battle_init+=1;
			if(battle_init==500){
                generate_enemies(5+stage,3);
                if(stage<14)    stage+=1;
            }
        i=0;
        while(i<personajes.size()){
            personajes[i].change_state('w');
            i+=1;
            }
        }

}

void juego::fight(){
    if(battle_init>499){
            if(action==-1){
                action=compare(imagenes);
            }
        //Boton Atacar
        if(action==14){
              int aliado=-1;
              int enemigo=-1;
              //seleccion de objetivo
                if(aliado==-1&&enemigo==-1){
                    aliado= hit(personajes);
                    enemigo= hit(figuras);

                }
                if(aliado!=-1){
                   personajes[aliado].change_state('d');
                   action=-1;

                }
                if(enemigo!=-1){
                    figuras[enemigo].change_state('d');
                    action=-1;

                }


    }
        }
        //Boton Curar
         if(action==15){
             int aliado=-1;
              int enemigo=-1;
                if(aliado==-1&&enemigo==-1){
                    aliado= hit(personajes);
                    enemigo= hit(figuras);

                }
                if(aliado!=-1){
                   personajes[aliado].change_state('h');
                   action=-1;

                }
                if(enemigo!=-1){
                    figuras[enemigo].change_state('h');
                    action=-1;

                }


        }



    }

    void juego::generate_enemies(int type,int amount){
        size_t enemies=0;
        figuras.clear();
    while(enemies<amount){
        addFigure(type);
        figuras[enemies].move_position(sf::Vector2f(800-50-100*enemies,542));
        enemies+=1;
    }
    }
