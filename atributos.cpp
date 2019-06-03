#include "atributos.hpp"

    atrib::atrib(){
        init_caracter(0);
    }
    atrib::atrib(int name){
        init_caracter(name);
        current_life=life;
    }
    void atrib::init_caracter(int name){
        switch(name){
            //Caballero
            case(0):
                life=300;
                magic_mult=1;
                flat_damage=30;
                flat_heal=5;
                break;
            //Mago
            case(1):
                life=100;
                magic_mult=3;
                flat_damage=10;
                flat_heal=10;
                break;
            //Cazador
            case(2):
                life=210;
                magic_mult=2;
                flat_damage=20;
                flat_heal=5;
                break;
             //Clerigo
            case(3):
                life=300;
                magic_mult=3;
                flat_damage=30;
                flat_heal=30;
                break;
               //Picaro
            case(4):
                life=150;
                magic_mult=1;
                flat_damage=40;
                flat_heal=5;
                break;
                //Mujer
            case(5):
                life=200;
                magic_mult=2;
                flat_damage=20;
                flat_heal=15;
                break;
             //Cyclope
            case(6):
                life=600;
                magic_mult=1;
                flat_damage=40;
                flat_heal=0;
                break;
             //Fantasma
            case(7):
                life=700;
                magic_mult=3;
                flat_damage=20;
                flat_heal=0;
                break;
            //Diablillo
            case(8):
                life=800;
                magic_mult=3;
                flat_damage=30;
                flat_heal=0;
                break;
                //Caballero Oscuro
            case(9):
                life=900;
                magic_mult=1;
                flat_damage=40;
                flat_heal=0;
                break;
                //Mago Oscuro
            case(10):
                life=900;
                magic_mult=3;
                flat_damage=30;
                flat_heal=10;
                break;
                //Cosa Huevo
            case(11):
                life=800;
                magic_mult=1;
                flat_damage=15;
                flat_heal=0;
                break;
                //Mounstro del Pantano
            case(12):
                life=1000;
                magic_mult=1;
                flat_damage=20;
                flat_heal=0;
                break;
                //Abeja
            case(13):
                life=1500;
                magic_mult=1;
                flat_damage=45;
                flat_heal=20;
                break;
            default:
                life=0;
                magic_mult=0;
                flat_damage=0;
                flat_heal=0;
                break;
        }
        current_life=life;
    }
    int atrib::damage(){
        std::srand(time(NULL));
        int mult=rand()%2;
        return -(flat_damage*magic_mult+flat_damage*magic_mult*mult);
    }
    int atrib::heal(){
        std::srand(time(NULL));
        int mult=rand()%3;
        return flat_heal*magic_mult+flat_heal*magic_mult*mult;
    }

    void atrib::damage_in(int damg){
        int result=current_life+damg;
        if(result>life) current_life=life;
        else if(result<0) current_life=0;
        else current_life=result;
    }
