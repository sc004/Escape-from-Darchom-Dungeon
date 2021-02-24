#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>

class Player {
    protected:
        
    public:
        int health;
        int attack;
        int defense; 
        int speed;
        Player() {
            health = 10;
            attack = 5;
            defense = 7; 
            speed = 3;
        }
	int get_health() {return health;}
};

#endif //__PLAYER_HPP__
