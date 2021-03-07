#ifndef TRAPENCOUNTERFACTORY_H
#define TRAPENCOUNTERFACTORY_H

#include <iostream>
#include <string>
#include "encounterfactory.h"
#include "trapEncounter.h"

using namespace std;
class TrapEncounterFactory: public EncounterFactory{
	public:
		TrapEncounterFactory(){}
		~TrapEncounterFactory();
		virtual Encounter* makeEncounter(){
			Encounter* trap = new Trap_Encounter(2);
			return trap;
		}
};
#endif //TRAPENCOUNTERFACTORY_H
