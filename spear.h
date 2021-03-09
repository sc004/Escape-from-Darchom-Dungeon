#ifndef SPEAR_H
#define SPEAR_H

#include <iostream>
#include <string>
#include "weapon.h"
using namespace std;

class spear : public weapon{
	private:
		int attack;
	public:
		spear(int id, string n, int dur, int atk): weapon(id, n, 2, dur){
			attack = atk;
			//2 = advantage vs troll
		}
		~spear(){}
		int get_attack(){
			return attack;
		}
};
#endif //SPEAR_H
