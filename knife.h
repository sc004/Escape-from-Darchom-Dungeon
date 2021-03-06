#ifndef KNIFE_H
#define KNIFE_H

#include <iostream>
#include <string>
#include "weapon.h"
using namespace std;

class Knife : public weapon{
	public:
		Knife(): weapon(99, "Knife", 0, 10){

		}
		~shield();
		int get_defense(){
			return defense;
		}
};
#endif //KNIFE_H
