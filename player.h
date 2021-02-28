#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "item.h"

#include <iostream>

class Player {
    protected:
        
    public:
        int health;
        int attack;
        int defense; 
        int speed;
	int status;
	bool gotItem;
        Player() {
       		health = 100;
        	attack = 5;
        	defense = 10; 
        	speed = 3;
        }
	void Add_Item(item* b){
		gotItem = true;
	}
	void get_health() {return health;}
	void get_defense() {return defense;}
};

#endif //__PLAYER_HPP__
