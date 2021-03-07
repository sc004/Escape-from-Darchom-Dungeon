#ifndef LEVEL_H
#define LEVEL_H

#include "encounter.h"
#include <string>
#include <iostream>

using namespace std;
class Level{
	private:
	int <Encounter*> encounters;
	string name;	
	public:
	Level();
	~Level();
};
#endif //LEVEL_H
