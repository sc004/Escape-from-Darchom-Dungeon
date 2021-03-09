#ifndef ENEMYENCOUNTERFACTORY_H
#define ENEMYENCOUNTERFACTORY_H

#include <iostream>
#include <string>
#include "encounterfactory.h"
#include "enemyencounter.h"

using namespace std;
class EnemyEncounterFactory: public EncounterFactory{
	public:
		vector<EnemyEncounter*> enemies;
		EnemyEncounterFactory(){}
		~EnemyEncounterFactory(){
			for(int i=0;i<enemies.size();i++){
                                delete enemies.at(i);
                        }
		}
		virtual Encounter* makeEncounter(){
			EnemyEncounter* enemy = new EnemyEncounter(1);
			enemies.push_back(enemy);
			return enemy;
		}
};
#endif //ENEMYENCOUNTERFACTORY_H
