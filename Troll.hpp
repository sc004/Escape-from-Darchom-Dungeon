#ifndef __TROLL_HPP__
#define __TROLL_HPP__

#include <iostream>
#include "Enemy.hpp"
#include "item.h"

class Troll : public Enemy {
    private:
        item* weapon = nullptr;
        item* loot = nullptr;
    public:
        Troll(int hp, int attack, int defense, int speed, int weakness, std::string n, item* w, item* l) :
            Enemy(hp, attack, defense, speed, weakness, n) {
                weapon = w;
                loot = l;
            }
	~Troll();
	int useSwipe(int pHP, int pDef){
            	int damage = (int)((5*get_attack())/(pDef+1))+1;
            	return pHP - damage;
        }
        int useSlam(int pHP, int pDef) {
            	int damage = (int)((5*get_attack())/(pDef+1))+1;
            	return pHP - damage;
        }
        virtual int enemyAttk(int pHP, int pDef) {
            srand(time(0));
            int val = rand() % 2 + 1;
            if (val == 0) {
                return useSwipe(pHP, pDef);
            }
            else {
                return useSlam(pHP, pDef);
            }
        }
        item* get_weapon() {return weapon;}
        item* get_loot() {return loot;}

};

#endif // __TROLL_HPP__
