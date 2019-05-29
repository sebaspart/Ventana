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
