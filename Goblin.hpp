#ifndef __GOBLIN_HPP__
#define __GOBLIN_HPP__

#include <iostream>
#include "Enemy.hpp"
#include "item.h"
#include "player.h"

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
         void useSlash (Player* p1){
		int damage = (int)((3*get_attack())/(p1->get_defense()+1))+1;
            	p1->set_health(p1->get_health() - damage);
        }
        void useStab(Player* p1) {
            	int damage = (int)((5*get_attack())/(p1->get_defense()+1))+1;
            	p1->set_health(p1->get_health() - damage);
        }
        virtual void enemyAttk(Player* p1) {
            srand(time(0));
            int val = rand() % 2 + 1;
            if (val == 0) {
                useSlash(p1);
            }
            else {
                useStab(p1);
            }
        }
        item* get_weapon() {return weapon;}
        item* get_loot() {return loot;}

};

#endif // __GOBLIN_HPP__
