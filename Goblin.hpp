#ifndef __GOBLIN_HPP__
#define __GOBLIN_HPP__

#include <iostream>
#include "Enemy.hpp"
#include "Item.hpp"

class Goblin : public Enemy {
    private:
        Item* weapon = nullptr;
        Item* loot = nullptr;
   public:
        Goblin(int hp, int attack, int defense, int speed, int weakness, std::string n, Item* w, Item* l) :
            Enemy(hp, attack, defense, speed, weakness, n) {
                weapon = w;
                loot = l;
         }
	~Goblin();
         void useSlash (Player* p1){
            p1->health -= 3*get_attack();
        }
        void useStab(Player* p1) {
            p1->health -= 5*get_attack();
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
        Item* get_weapon() {return weapon;}
        Item* get_loot() {return loot;}

};

#endif // __GOBLIN_HPP__
