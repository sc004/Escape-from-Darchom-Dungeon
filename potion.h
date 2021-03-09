#ifndef POTION_H
#define POTION_H

#include "player.h"
#include "item.h"


class Potion: public item{
	public:
		Potion(int id, string name) : item(id,name){}
		~Potion(){}
	virtual void increaseStats(Player* p1) = 0;
};

#endif
