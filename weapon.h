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
		weapon(int i, string n, int aP, int d) : item(i, n){
			advPoints = aP;
			durability = d;
			}
		~weapon(){}
		int get_advPoints(){
			return advPoints;
		}
		int get_timesUsed(){
			return timesUsed;
		}
		int get_durability(){
			return durability;
		}
		void increase_timesUsed(){
			timesUsed++;
			durability --;
		}

};
#endif //WEAPON_H
