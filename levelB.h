#ifndef LEVEL_B
#define LEVEL_B
#include "level.h"
#include "trapencounterfactory.h"
#include "itemencounterfactory.h"
#include "enemyencounterfactory.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>

class LevelB: public Level{
        private:
                int levelID;

        public:
                LevelB(){
			EncounterFactory* enemy = new EnemyEncounterFactory();
                        EncounterFactory* trap = new TrapEncounterFactory();
                        EncounterFactory* item = new ItemEncounterFactory();
			//srand((unsigned) time(0));
                        for(int i = 0; i < 7; i++){
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
                        levelID = 2;
                        delete enemy;
                        delete trap;
                        delete item;
                }
                ~LevelB();/*
			for(int i=0;i<encounters.size();i++){
                        	delete encounters.at(i);
                	}
                	encounters.clear();*/
		
};

#endif
