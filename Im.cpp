#include "Im.hpp"
    Im::Im(){
        asignation(0,0);
        inicial=Base.getColor();
    }

    //tipo de objeto e indice de imagen del objeto
    Im::Im(int type, int index){
        asignation(type,index);


        inicial=Base.getColor(); //color de referencia inicial
    }

    void Im::recolor(const char indicador){
        //modificar color base del sprite
        switch (indicador)
        {
            //verde heal
            case 'h':
                Base.setColor(sf::Color(0,255,0));

            break;
            //gris muerto
            case 'g':
                Base.setColor(sf::Color(130,130,130));

            break;
            //rojo daño
            case 'r':
                Base.setColor(sf::Color(255,0,0));

            break;
            //else
            default:
                Base.setColor(inicial); //regreso al color inicial
             break;


        }

    }

    void Im::set_scale(float fact){
        if (fact<0){
            Base.setScale(fact,-fact);
            factor=-fact;

        }
        else{
        Base.setScale(fact,fact);
        factor=fact;
        }

    }

    void Im::position_set(sf::Vector2f position){
        Base.setPosition(position);

    }
    void Im::position_set(sf::Vector2i position){
        Base.setPosition(position.x,position.y);

    }

    sf::Vector2f Im::position_get(){
        return Base.getPosition();

    }


    void Im::position_move(float x, float y){
        Base.move(x,y);
    }

                            //  PERSONAJES


    //Seleccion de sprites para manejo de un personaje u objeto
    int Im::asignation(int type, int index){



                        // HEROES

    //                 TIPO 0      CABALLERO
    if(type ==0){
                if(!Imagen[0].loadFromFile("Imagenes/Human/Front/knight1.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Human/Side/knight1.png")){
            return -1;
            }

            switch (index){
            case 0:

                //caso 1 de figura
                Base.setTexture(Imagen[0]);
                Base.setPosition(300,150);
                Base.setTextureRect(sf::IntRect(0,2,15,15));
                {sf::Vector2f centro;
                centro.x=Base.getTextureRect().width/2.f;
                centro.y=Base.getTextureRect().height/2.f;
                Base.setOrigin(centro);
                }
                set_scale(4);
                break;
            case 1:
                 Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-4);
        break;

            }

    }
    //                 TIPO 1       MAGO
    if(type==1){
            if(!Imagen[0].loadFromFile("Imagenes/Human/Front/wizard4.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Human/Side/wizard4.png")){
            return -1;
            }

            switch (index){
        case 0:
            Base.setTexture(Imagen[0]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(0,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(4);
        break;
        case 1:
            Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-4);

        break;

            }

    }
        //             TIPO 2       HUNTER
        if(type==2){
            if(!Imagen[0].loadFromFile("Imagenes/Human/Front/hunter2.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Human/Side/hunter2.png")){
            return -1;
            }

            switch (index){
        case 0:
            Base.setTexture(Imagen[0]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(0,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(4);
        break;
        case 1:
            Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-4);

        break;

            }

    }
        //           TIPO 3         CLERIC
        if(type==3){
            if(!Imagen[0].loadFromFile("Imagenes/Human/Front/cleric3.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Human/Side/cleric3.png")){
            return -1;
            }

            switch (index){
        case 0:
            Base.setTexture(Imagen[0]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(0,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(4);
        break;
        case 1:
            Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-4);
        break;


            }

    }


        //           TIPO 4         ROGUE
        if(type==4){
            if(!Imagen[0].loadFromFile("Imagenes/Human/Front/rogue4.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Human/Side/rogue4.png")){
            return -1;
            }

            switch (index){
        case 0:
            Base.setTexture(Imagen[0]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(0,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(4);
        break;
        case 1:
            Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-4);
        break;

            }

    }


        //           TIPO 5         FEMALE
        if(type==5){
            if(!Imagen[0].loadFromFile("Imagenes/Human/Front/adventurer_f4.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Human/Side/adventurer_f4.png")){
            return -1;
            }

            switch (index){
        case 0:
            Base.setTexture(Imagen[0]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(0,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(4);
        break;
        case 1:
            Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-4);
        break;

            }

    }


                    //  VILLANOS

        //           TIPO 6         CYCLOPS
        if(type==6){
            if(!Imagen[0].loadFromFile("Imagenes/Monsters/monster_49.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Monsters/monster_49.png")){
            return -1;
            }

            switch (index){
        case 0:
            Base.setTexture(Imagen[0]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(3);
        break;
        case 1:
            Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-3);
        break;

            }

    }
       //           TIPO 7         GHOST
        if(type==7){
            if(!Imagen[0].loadFromFile("Imagenes/Monsters/monster_34.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Monsters/monster_34.png")){
            return -1;
            }

            switch (index){
        case 0:
            Base.setTexture(Imagen[0]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(0,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(3);
        break;
        case 1:
            Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-3);
        break;

            }

    }
           //           TIPO 8         IMP (DIABLILLO)
        if(type==8){
            if(!Imagen[0].loadFromFile("Imagenes/Monsters/monster_48.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Monsters/monster_48.png")){
            return -1;
            }

            switch (index){
        case 0:
            Base.setTexture(Imagen[0]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(0,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(3);
        break;
        case 1:
            Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-3);
        break;

            }

    }

           //           TIPO 9         DARK KNIGHT
        if(type==9){
            if(!Imagen[0].loadFromFile("Imagenes/Monsters/monster_112.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Monsters/monster_112.png")){
            return -1;
            }

            switch (index){
        case 0:
            Base.setTexture(Imagen[0]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(0,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(3);
        break;
        case 1:
            Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-3);
        break;

            }

    }
           //           TIPO 10         DARK MAGE
        if(type==10){
            if(!Imagen[0].loadFromFile("Imagenes/Monsters/monster_104.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Monsters/monster_104.png")){
            return -1;
            }

            switch (index){
        case 0:
            Base.setTexture(Imagen[0]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(0,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(3);
        break;
        case 1:
            Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(3);
        break;

            }

    }
           //           TIPO 11        EGG THING
        if(type==11){
            if(!Imagen[0].loadFromFile("Imagenes/Monsters/monster_85.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Monsters/monster_85.png")){
            return -1;
            }

            switch (index){
        case 0:
            Base.setTexture(Imagen[0]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(0,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(3);
        break;
        case 1:
            Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-3);
        break;

            }

    }
           //           TIPO 12         SWAMP MONSTER
        if(type==12){
            if(!Imagen[0].loadFromFile("Imagenes/Monsters/monster_84.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Monsters/monster_84.png")){
            return -1;
            }

            switch (index){
        case 0:
            Base.setTexture(Imagen[0]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(0,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(3);
        break;
        case 1:
            Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-3);
        break;

            }

    }
           //           TIPO 13        BEE
        if(type==13){
            if(!Imagen[0].loadFromFile("Imagenes/Monsters/monster_25.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Monsters/monster_25.png")){
            return -1;
            }

            switch (index){
        case 0:
            Base.setTexture(Imagen[0]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(0,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(3);
        break;
        case 1:
            Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-3);
        break;

            }

    }
            //           TIPO 14   Recuadro atacar
        if(type==14){
            if(!Imagen[0].loadFromFile("Imagenes/atacar.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/atacar.png")){
            return -1;
            }
            switch (index){
            case 0:
            Base.setTexture(Imagen[1]);
            Base.setTextureRect(sf::IntRect(253,115,796,494));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
            set_scale(.1);
            Base.setPosition(469,46);


                break;
            case 1:
            Base.setTexture(Imagen[1]);
            Base.setTextureRect(sf::IntRect(253,115,796,494));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
            set_scale(.1);
            Base.setPosition(469,46);
            break;
            }
        }

        //          TIPO 15            Recuadro Curar
        if(type==15){
            if(!Imagen[0].loadFromFile("Imagenes/curar.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/curar.png")){
            return -1;
            }
            switch (index){
            case 0:
            Base.setTexture(Imagen[1]);
            Base.setTextureRect(sf::IntRect(253,115,796,494));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
            set_scale(.1);

            Base.setPosition(626,46);
                break;
            case 1:
            Base.setTexture(Imagen[1]);
            Base.setTextureRect(sf::IntRect(253,115,796,494));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
            set_scale(.1);
            Base.setPosition(626,46);
            break;
            }
        }
                // TIPO 16 Imagen presentacion de personajes
        if(type==16){
            if(!Imagen[0].loadFromFile("Imagenes/fondo_personajes.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/fondo_personajes.png")){
            return -1;
            }
            switch (index){
            case 0:
            Base.setTexture(Imagen[1]);
            Base.setTextureRect(sf::IntRect(0,0,1920,1080));
            Base.setScale(sf::Vector2f(.43,.57));
            Base.setPosition(0,0);

                break;
            case 1:
            Base.setTexture(Imagen[1]);
            Base.setTextureRect(sf::IntRect(0,0,1920,1080));
            Base.setScale(sf::Vector2f(.41,.55));
            Base.setPosition(0,0);

            break;
            }
        }
        //          TIPO 17    Recuadro Info seleccion personajes
        if(type==17){
            if(!Imagen[0].loadFromFile("Imagenes/personajes.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/personajes.png")){
            return -1;
            }
            switch (index){
            case 0:
            Base.setTexture(Imagen[1]);
            Base.setTextureRect(sf::IntRect(253,115,796,494));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
            //Posicion del cartel
            Base.setPosition(227,79);
            set_scale(.2);


                break;
            case 1:
            Base.setTexture(Imagen[1]);
            Base.setTextureRect(sf::IntRect(253,115,796,494));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
            //     Posicion del cartel
            Base.setPosition(227,79);
            set_scale(.2);
            break;
            }
        }

            //  TIPO 18             Fondo principal de inicio
        if(type==18){
            if(!Imagen[0].loadFromFile("Imagenes/main.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/main.png")){
            return -1;
            }
            switch (index){
            case 0:
            Base.setTexture(Imagen[1]);
            Base.setTextureRect(sf::IntRect(0,0,800,600));
            Base.setScale(1,1);
            Base.setPosition(10,8);
                break;
            case 1:
            Base.setTexture(Imagen[1]);
            Base.setTextureRect(sf::IntRect(0,0,800,600));
            Base.setScale(1,1);
            Base.setPosition(0,0);
            break;
            }


        }

        //  TIPO 19                 Recuadro Iniciar
        if(type==19){
                if(!Imagen[0].loadFromFile("Imagenes/start.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/start.png")){
            return -1;
            }
             switch (index){
            case 0:
            Base.setTexture(Imagen[1]);

             Base.setTextureRect(sf::IntRect(9,74,237,108));
             {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
            set_scale(1);
            Base.setPosition(233,232);

                break;
            case 1:
            Base.setTexture(Imagen[1]);
             Base.setTextureRect(sf::IntRect(9,74,237,108));
             {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
            Base.setPosition(233,232);
            set_scale(1);
            break;
            }


        }

           //  TIPO 20                 Recuadro Salir
        if(type==20){
                if(!Imagen[0].loadFromFile("Imagenes/SALIR.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/SALIR.png")){
            return -1;
            }
            switch (index){
            case 0:
            Base.setTexture(Imagen[1]);

             Base.setTextureRect(sf::IntRect(13,74,231,108));
             {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
            Base.setPosition(527,232);
            set_scale(1);
                break;
            case 1:
            Base.setTexture(Imagen[1]);
             Base.setTextureRect(sf::IntRect(13,74,231,108));
             {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
            Base.setPosition(527,232);
            set_scale(1);
            break;
            }


        }


        // Casos para evitar conflicto de OpenGL
    if(type<0||type>21){
            if(!Imagen[0].loadFromFile("Imagenes/Human/Front/knight1.png")){
            return -1;
            }
                if(!Imagen[1].loadFromFile("Imagenes/Human/Side/knight1.png")){
            return -1;
            }

            switch (index){
            case 0:

                //caso 1 de figura
                Base.setTexture(Imagen[0]);
                Base.setPosition(300,150);
                Base.setTextureRect(sf::IntRect(0,2,15,15));
                {sf::Vector2f centro;
                centro.x=Base.getTextureRect().width/2.f;
                centro.y=Base.getTextureRect().height/2.f;
                Base.setOrigin(centro);
                }
                set_scale(3);
                break;
            case 1:
                 Base.setTexture(Imagen[1]);
        Base.setPosition(200,150);
        Base.setTextureRect(sf::IntRect(16,0,15,15));
        {sf::Vector2f centro;
        centro.x=Base.getTextureRect().width/2.f;
        centro.y=Base.getTextureRect().height/2.f;
        Base.setOrigin(centro);
        }
        set_scale(-3);
        break;

    }

    }



    return 0;
    }

    sf::Sprite Im::draw(){
        return Base;
    }


    sf::Vector2f Im::rect(){
        sf::Vector2f bounds;
        bounds.x=Base.getTextureRect().width/2.f*factor;
        bounds.y=Base.getTextureRect().height/2.f*factor;
        return bounds;
    }
