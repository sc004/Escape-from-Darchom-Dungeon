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
	void useSwipe(Player* p1){
            p1->set_health(p1->get_health() - (5*get_attack()));
        }
        void useSlam(Player* p1) {
            p1->set_health(p1->get_health() - (3*get_attack()));
        }
        virtual void enemyAttk(Player* p1) {
            srand(time(0));
            int val = rand() % 2 + 1;
            if (val == 0) {
                useSwipe(p1);
            }
            else {
                useSlam(p1);
            }
        }
        item* get_weapon() {return weapon;}
        item* get_loot() {return loot;}

};

#endif // __TROLL_HPP__
