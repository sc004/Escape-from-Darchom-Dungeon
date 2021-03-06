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
		~Knife();
};
#endif //KNIFE_H
