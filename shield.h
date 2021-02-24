#ifndef SHIELD_H
#define SHIELD_H

#include <iostream>
#include <string>
#include "weapon.h"
using namespace std;

class shield : public weapon{
	private:
		int defense;
	public:
		shield(int id, string n, int dur, int def): weapon(id, n, 0, dur){
			defense= def;
			//0 sent to the weapon class indicates no advantage
		}
		~shield();
		int get_defense(){
			return defense;
		}
};
#endif //SHIELD_H
