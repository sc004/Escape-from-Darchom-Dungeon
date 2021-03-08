#ifndef LEVEL_H
#define LEVEL_H

#include "encounter.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Level{
	protected:
	vector<Encounter*> encounters;
	string name;	
	public:
	Level(){}
	~Level(){}
	vector<Encounter*> getEncounters(){
		return encounters;
	}
};
#endif //LEVEL_H
