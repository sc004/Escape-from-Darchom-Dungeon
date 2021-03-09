#ifndef ENEMYENCOUNTERFACTORY_H
#define ENEMYENCOUNTERFACTORY_H

#include <iostream>
#include <string>
#include "encounterfactory.h"
#include "enemyencounter.h"

using namespace std;
class EnemyEncounterFactory: public EncounterFactory{
	public:
		EnemyEncounterFactory(){}
		~EnemyEncounterFactory(){}
		virtual Encounter* makeEncounter(){
			Encounter* enemy = new EnemyEncounter(1);
			return enemy;
		}
};
#endif //ENEMYENCOUNTERFACTORY_H
