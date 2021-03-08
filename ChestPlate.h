#ifndef CHESTPLATE_H
#define CHESTPLATE_H
#include <iostream>
#include "armor.h"
class ChestPlate : public Armor{
   private:
	int defense;
   public:
	ChestPlate(int i, std::string n, int d) : Armor(i, n, d) {
		defense =  d;
	}
	~ChestPlate();
	virtual void increaseStats(Player* p1) {
		int playerD = p1->get_defense();
		playerD += defense;
		p1->set_defense(playerD);
	}
};

#endif
