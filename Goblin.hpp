#ifndef __GOBLIN_HPP__
#define __GOBLIN_HPP__

#include <iostream>
#include "Enemy.hpp"
#include "item.h"


class Goblin : public Enemy {
    private:
        item* weapon = nullptr;
        item* loot = nullptr;
   public:
        Goblin(int hp, int attack, int defense, int speed, int weakness, std::string n, item* w, item* l) :
            Enemy(hp, attack, defense, speed, weakness, n) {
                weapon = w;
                loot = l;
         }
	~Goblin();
        int useSlash (int pHP, int pDef){
		int damage = (int)((3*get_attack())/(pDef+1))+1;
            	return pHP - damage;
        }
        int useStab(int pHP, int pDef) {
            	int damage = (int)((5*get_attack())/(pDef+1))+1;
            	return pHP - damage;
        }
        virtual int enemyAttk(int pHP, int pDef) {
            srand(time(0));
            int val = rand() % 2 + 1;
            if (val == 0) {
                return useSlash(p1);
            }
            else {
                return useStab(p1);
            }
        }
        item* get_weapon() {return weapon;}
        item* get_loot() {return loot;}

};

#endif // __GOBLIN_HPP__
