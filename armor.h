#ifndef ARMOR_H
#define ARMOR_H
#include <iostream>
#include "item.h"
#include "Player.hpp"

class Armor : public item {
    private:
	int defense;
    public:
	Armor(int i, std::string n, int d) : item(i, n) {
		defense = d;
	}
	~Armor();
	int get_defense() {
		return defense;
	}
	virtual void increaseStats(Player* p1) = 0;
};	

#endif
