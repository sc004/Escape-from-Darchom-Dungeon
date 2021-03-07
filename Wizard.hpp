#ifndef __WIZARD_HPP__
#define __WIZARD_HPP__

#include <iostream>
#include "Enemy.hpp"
#include "item.h"

class Wizard : public Enemy {
    private:
        item* loot = nullptr;
    public: 
        Wizard(int hp, int attack, int defense, int speed, int weakness, std::string n, item* l) :
            Enemy(hp, attack, defense, speed, weakness, n) {
                loot = l;
            }
	~Wizard();
	void useFireball(Player* p1){
            	int damage = (int)((9*get_attack())/((p1->get_defense())/2+1))+1;
            	p1->set_health(p1->get_health() - damage);
        }
        void useLightning(Player* p1) {
            	int damage = (int)((7*get_attack())/((p1->get_defense())/2+1))+1;
            	p1->set_health(p1->get_health() - damage);
        }
        void useMagicMissle(Player* p1) {
            	int damage = (int)((5*get_attack())/((p1->get_defense())/2+1))+1;
            	p1->set_health(p1->get_health() - damage);
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

        item* get_loot() {return loot;}

};

#endif // __WIZARD_HPP__
