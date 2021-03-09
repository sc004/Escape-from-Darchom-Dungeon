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
	~Wizard(){
		if(loot !=nullptr||loot !=NULL){
                        delete loot;
                }
	}
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
                return useFireball(pHP, pDef);
            }
            else if (val == 1) {
                return useLightning(pHP, pDef);
            }
            else {
                return useMagicMissle(pHP, pDef);
            }
        }

        item* get_loot() {
                item* temp= loot;
                loot = nullptr;
                return temp;
        }

};

#endif // __WIZARD_HPP__
