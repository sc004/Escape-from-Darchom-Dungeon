#ifndef __WIZARD_HPP__
#define __WIZARD_HPP__

#include <iostream>
#include "Enemy.hpp"
#include "Item.hpp"

class Wizard : public Enemy {
    private:
        Item* loot = nullptr;
    public: 
        Wizard(int hp, int attack, int defense, int speed, int weakness, std::string n, Item* l) :
            Enemy(hp, attack, defense, speed, weakness, n) {
                loot = l;
            }
	~Wizard();
	void useFireball(Player* p1){
            p1->health -= 9*get_attack();
        }
        void useLightning(Player* p1) {
            p1->health -= 7*get_attack();
        }
        void useMagicMissle(Player* p1) {
            p1->health -= 5*get_attack();
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
