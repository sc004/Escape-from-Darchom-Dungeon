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
		sword(int id, int dur, string n, int atk){
			this->itemID = id;
			this->durability = dur;
			this->name = n;
			attack = atk;
			this->advPoints = 1;//advantage vs goblin
		}
		~sword();
		int get_attack(){
			return attack;
		}
};
#endif //SWORD_H
