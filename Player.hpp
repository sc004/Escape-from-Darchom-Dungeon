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
            health = 120;
            attack = 5;
            defense = 10;
            speed = 3;
        }
	~Player();
	int get_health() {return health;}
	int get_defense() {return defense;}
};

#endif //__PLAYER_HPP__
