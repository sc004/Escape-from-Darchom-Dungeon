#ifndef LEVEL_H
#define LEVEL_H

#include "encounter.h"
#include <string>
#include <iostream>
#include <vector>
#include "enemyencounter.h"
#include "Item_Encounter.h"
#include "trapEncounter.h"
using namespace std;


class Level{
	protected:
	vector<Encounter*> encounters;
	string name;	
	public:
	Level(){}
	~Level(){
		/*for(int i=0;i<encounters.size();i++){
			delete encounters.at(i);
		}*/
		//encounters.clear();
		while(!encounters.empty()) {
        		delete encounters.back();
        		encounters.pop_back();
    		}
		cout <<"deleted a level's encounters\n";
		//delete encounters;
	}
	vector<Encounter*> getEncounters(){
		return encounters;
	}
};
#endif //LEVEL_H
