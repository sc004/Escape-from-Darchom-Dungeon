
#ifndef LEVEL_A
#define LEVEL_A
#include "level.h"
#include "trapencounterfactory.h"
#include "itemencounterfactory.h"
#include "enemyencounterfactory.h"
#include <iostream>

class LevelA: public Level{
	private:
		int levelID;

	public:
		LevelA(){
			for(i = 0; i < 5; i++){
				int rand = (rand() % 3) + 1;
				if(rand == 1){
					EncounterFactory* enemy = new EnemyEncounterFactory();
					encounters.push_back(enemy->makeEncounter());
				}
				if(rand == 2){
					EncounterFactory* trap = new TrapEncounterFactory();
					encounters.push_back(trap->makeEncounter());
				}
				if(rand == 3){
					EncounterFactory* item = new ItemEncounterFactory();
					encounters.push_back(item->makeEncounter());
				
				}	
			}
			levelID = 1;
			delete[] enemy;
			delete[] trap;
			delete[] item;
		}
		~LevelA(){}
};

#endif
