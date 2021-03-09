#ifndef ARMOR_H
#define ARMOR_H
#include <iostream>
#include "item.h"
#include "player.h"

class Armor : public item {
    private:
	int defense;
	bool isEquiped = false;
    public:
	Armor(int i, std::string n, int d) : item(i, n) {
		defense = d;
	}
	~Armor(){}
	int get_defense() {
		return defense;
	}
	virtual bool get_isEquiped() { return isEquiped;}
	virtual void set_isEquiped(bool equip) {
		isEquiped = equip;
	}
	virtual void increaseStats(Player* p1) = 0;
};	

#endif
