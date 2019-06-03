#ifndef ATRIBUTOS_HPP
#define ATRIBUTOS_HPP
    #include <time.h>
    #include <stdlib.h>
    class atrib{
    public:
    atrib();
    atrib(int name);
    void init_caracter(int name);
    int damage();
    void damage_in(int damg);
    int heal();
    int current_life;
    private:
    int life;
    int magic_mult;
    int flat_damage;
    int flat_heal;




    };



#endif // ATRIBUTOS_HPP
