#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
#include "item.h"
using namespace std;

class weapon : public item{
	private:
		int advPoints;
		int timesUsed;
		int durability;
	public:
		weapon();
		~weapon();
		int get_advPoints(){
			return advPoints;
		}
		int get_timesUsed(){
			return timesUsed;
		}
		int get_durability(){
			return durability;
		}

};
#endif //WEAPON_H
