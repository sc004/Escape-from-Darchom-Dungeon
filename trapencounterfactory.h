#ifndef TRAPENCOUNTERFACTORY_H
#define TRAPENCOUNTERFACTORY_H

#include <iostream>
#include <string>
#include "encounterfactory.h"
#include "trapEncounter.h"
#include <iostream>
#include <vector>

using namespace std;

class TrapEncounterFactory: public EncounterFactory{
	public:
		vector<Trap_Encounter*> traps;
		TrapEncounterFactory(){}
		~TrapEncounterFactory(){
			for(int i=0;i<traps.size();i++){
                        	delete traps.at(i);
                	}
		}
		virtual Encounter* makeEncounter(){
			Trap_Encounter* trap = new Trap_Encounter(2);
			traps.push_back(trap);
			return trap;
		}
};
#endif //TRAPENCOUNTERFACTORY_H
