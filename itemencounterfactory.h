#ifndef ITEMENCOUNTERFACTORY_H
#define ITEMENCOUNTERFACTORY_H

#include <iostream>
#include <string>
#include "encounterfactory.h"
#include "Item_Encounter.h"
#include <iostream>

using namespace std;
class ItemEncounterFactory: public EncounterFactory{
	public:
		vector<ItemEncounter*> items;
		ItemEncounterFactory(){}
		~ItemEncounterFactory(){
			for(int i=0;i<items.size();i++){
                                delete items.at(i);
                        }
		}
		virtual Encounter* makeEncounter(){
			ItemEncounter* item = new ItemEncounter(3);
			items.push_back(item);
			return item;
		}
};
#endif //ITEMENCOUNTERFACTORY_H
