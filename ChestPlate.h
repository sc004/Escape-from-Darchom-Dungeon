#ifndef CHESTPLATE_H
#define CHESTPLACE_H
#include <iostream>
#include "armor.h"
#include "player.h"

class ChestPlate : public Armor{
   private:
	int defense;
   public:
	ChestPlate(int i, std::string n, int d) : Armor(i, n, d) {
		defense =  d;
	}
	~ChestPlate();
	virtual void increaseStats(Player* p1) {
		p1->defense += defense;
	}
};

#endif
