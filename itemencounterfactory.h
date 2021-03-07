#ifndef ITEMENCOUNTERFACTORY_H
#define ITEMENCOUNTERFACTORY_H

#include <iostream>
#include <string>
#include "encounterfactory.h"
#include "Item_Encounter.h"

using namespace std;
class ItemEncounterFactory: public EncounterFactory{
	public:
		ItemEncounterFactory(){}
		~ItemEncounterFactory();
		virtual Encounter* makeEncounter(){
			Encounter* item = new ItemEncounter(3);
			return item;
		}
};
#endif //ITEMENCOUNTERFACTORY_H
