#ifndef BOW_H
#define BOW_H

#include <iostream>
#include <string>
#include "weapon.h"
using namespace std;

class bow : public weapon{
	private:
		int attack;
	public:
		bow(int id, string n, int dur, int atk): weapon(id, n, 3, dur){
			attack = atk;
			//3 sent to weapon indicates advantage vs wizard
		}
		~bow(){}
		int get_attack(){
			return attack;
		}
};
#endif //BOW_H
