#ifndef POTION_H
#define POTION_H

#include "item.h"


class Potion: public item{
	public:
		Potion(int id, string name) : item(id,name){}
		~Potion();
	
};

#endif
