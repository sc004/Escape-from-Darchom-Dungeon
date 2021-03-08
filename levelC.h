#ifndef LEVEL_C
#define LEVEL_C
#include "level.h"
#include "trapencounterfactory.h"
#include "itemencounterfactory.h"
#include "enemyencounterfactory.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class LevelC: public Level{
        private:
                int levelID;

        public:
                LevelC(){
			EncounterFactory* enemy = new EnemyEncounterFactory();
                        EncounterFactory* trap = new TrapEncounterFactory();
                        EncounterFactory* item = new ItemEncounterFactory();
                        for(int i = 0; i < 10; i++){
                                
				time_t t;
                                srand((unsigned) time(&t));
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
                        levelID = 3;
                        delete enemy;
                        delete trap;
                        delete item;
                }
                ~LevelC(){}
};

#endif

