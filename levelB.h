#ifndef LEVEL_B
#define LEVEL_B

using namespace std;

class LevelB: public Level{
        private:
                int levelID;

        public:
                LevelB(){
                        for(i = 0; i < 7; i++){
                                int rand = (rand() % 3) + 1;
                                if(rand == 1){
                                        Factory* enemy = new EnemyFactory();
                                        encounters.push_back(enemy->makeEncounter());
                                }
                                if(rand == 2){
                                        Factory* trap = new TrapFactory();
                                        encounters.push_back(trap->makeEncounter());
                                }
                                if(rand == 3){
                                        Factory* item = new ItemFactory();
                                        encounters.push_back(item->makeEncounter());

                                }
                        }
                        levelID = 1;
                        delete[] enemy;
                        delete[] trap;
                        delete[] item;
                }
                ~LevelB(){}
};

#endif
