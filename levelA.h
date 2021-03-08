
#ifndef LEVEL_A
#define LEVEL_A
#include "level.h"
#include "trapencounterfactory.h"
#include "itemencounterfactory.h"
#include "enemyencounterfactory.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>

class LevelA: public Level{
	private:
		int levelID;

	public:
		LevelA(){
			EncounterFactory* enemy = new EnemyEncounterFactory();
			EncounterFactory* trap = new TrapEncounterFactory();
			EncounterFactory* item = new ItemEncounterFactory();
			//srand((unsigned) time(0));
			for(int i = 0; i < 5; i++){
				int a = (rand() % 3) + 1;
				if(a == 1){
					
					encounters.push_back(enemy->makeEncounter());
				}
				if(a == 2){
					
					encounters.push_back(trap->makeEncounter());
				}
				if(a == 3){
					
					encounters.push_back(item->makeEncounter());
				
				}	
			}
			levelID = 1;
			delete enemy;
			delete trap;
			delete item;
		}
		~LevelA(){}
};

#endif
