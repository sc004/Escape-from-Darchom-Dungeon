#ifndef CLUB_H
#define CLUB_H

#include <iostream>
#include <string>
#include "weapon.h"
using namespace std;

class Club : public weapon{
	public:
		Club(): weapon(100, "Club", 0, 10){

		}
		~Club();
};
#endif //CLUB_H
