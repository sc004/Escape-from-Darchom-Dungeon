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
            int health = 10;
            int attack = 5;
            int defense = 7; 
            int speed = 3;
        }
};

#endif //__PLAYER_HPP__
