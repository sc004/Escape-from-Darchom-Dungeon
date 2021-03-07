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
	int useFireball(int pHP, int pDef){
            	int damage = (int)((9*get_attack())/(pDef/2+1))+1;
            	return pHP - damage;
        }
        int useLightning(int pHP, int pDef) {
            	int damage = (int)((7*get_attack())/(pDef/2+1))+1;
            	return pHP - damage;
        }
        int useMagicMissle(int pHP, int pDef) {
            	int damage = (int)((5*get_attack())/(pDef/2+1))+1;
            	return pHP - damage;
        }
        virtual int enemyAttk(int pHP, int pDef) {
            srand(time(0));
            int val = rand() % 3 + 1;
            if (val == 0) {
                return useFireball(p1);
            }
            else if (val == 1) {
                return useLightning(p1);
            }
            else {
                return useMagicMissle(p1);
            }
        }

        item* get_loot() {return loot;}

};

#endif // __WIZARD_HPP__
