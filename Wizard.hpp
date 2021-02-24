#ifndef __WIZARD_HPP__
#define __WIZARD_HPP__

#include <iostream>
#include "Enemy.hpp"
#include "Item.hpp"

class Wizard : public Enemy {
    private:
        Item* loot = nullptr;
    public:
        void useFireball(Player* p1){
            p1->health -= 7;
        }
        void useLightning(Player* p1) {
            p1->health -= 5;
        }
        void useMagicMissle(Player* p1) {
            p1->health -= 4;
        }
    
        Wizard(int hp, int attack, int defense, int speed, int weakness, std::string n, Item* l) :
            Enemy(hp, attack, defense, speed, weakness, n) {
                loot = l;
            }
        virtual void enemyAttk(Player* p1) {
            srand(time(0));
            int val = rand() % 3 + 1;
            if (val == 0) {
                useFireball(p1);
            }
            else if (val == 1) {
                useLightning(p1);
            }
            else {
                useMagicMissle(p1);
            }
        }

        Item* get_loot() {return loot;}

};

#endif // __WIZARD_HPP__
