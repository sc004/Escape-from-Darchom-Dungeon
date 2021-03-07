#ifndef LEVEL_C
#define LEVEL_C
#include "level.h"

using namespace std;

class LevelC: public Level{
        private:
                int levelID;

        public:
                LevelC(){
                        for(i = 0; i < 10; i++){
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
                        levelID = 3;
                        delete[] enemy;
                        delete[] trap;
                        delete[] item;
                }
                ~LevelC(){}
};

#endif

