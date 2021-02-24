#ifndef SWORD_H
#define SWORD_H

#include <iostream>
#include <string>
#include "weapon.h"
using namespace std;

class sword : public weapon{
	private:
		int attack;
	public:
		sword(int id, string n, int dur, int atk): weapon(id, n, 1, dur){
			attack = atk;
			//1 = advantage vs goblin
		}
		~sword();
		int get_attack(){
			return attack;
		}
};
#endif //SWORD_H
