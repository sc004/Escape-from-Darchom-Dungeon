#ifndef ITEM_ENCOUNTER
#define ITEM_ENCOUNTER
#include "encounter.h"
#include "item.h"
#include "player.h"
#include <string>
#include <iostream>

class ItemEncounter : public Encounter {
    private:
	Item* itemEncountered;
	bool hasReceived = false;
    public:
      ItemEncounter(int i) : Encounter(i){
	
	int type = rand() % 3 + 1;
	std::string prefix;
	if (type == 1) { prefix = "Basic";}
	else if(type == 2) { prefix = "Advanced";}
	else if(type == 3) {prefix = "Great";}
	
	int randNum = rand() % 10 + 1;
	if(randNum == 1) {
		itemEncountered = new sword(1, prefix + " Sword", type*5, type*7);  
	}
	else if(randNum == 2) {
                itemEncountered = new spear(2, prefix + " Spear", type*7, type*10);
        }
	else if(randNum == 3) {
                itemEncountered = new shield(3, prefix + " Shield", type*3, type*5);
        }
	else if(randNum == 4) {
                itemEncountered = new bow(4, prefix + " Bow", type*4, type*6);
        }
	else if(randNum == 5) {
                itemEncountered = new ChestPlate(5, prefix + " ChestPlate", type*4);
        }
	else if(randNum == 6) {
                itemEncountered = new Helmet(6, prefix + " Helmet", type*3);
        }
	else if(randNum == 7) {
                itemEncountered = new Greaves(7, prefix + " Greaves", type*1);
        }
	else if(randNum == 8) {
                itemEncountered = new DoubleHealth(8, "Double Health Potion");
        }
	else if(randNum == 9) {
                itemEncountered = new FullHealth(9, "Full Health Potion");
        }
	else if(randNum == 10) {
                itemEncountered = new IncreaseSpeed(10, "Increase Speed Potion");
        }
     } 
     ~ItemEncounter(){}
     void run(Player* p1) {
	std::char userIn;
	bool done = false;
	std::cout << "Would you like to pick up this item (" << itemEncountered->get_name() << ")? 1 for yes, 2 for no" << std::endl;
	while(done == false) {
             std::cin >> userIn;
	     if(userIn == '1'){
		p1->AddItems(itemEncountered);
		cout << "Player has picked up " << itemEncountered->get_name() << std::endl;
		hasReceived = true;
		done = true;
	     }
	     else if(userIn == '2'){
		std::cout << "Player has decided not to pick up " << itemEncountered->get_name() << std::endl;
	     	hasReceived = false;
	     	done = true;
	     }
	     else{
		std::cout << "Please enter a valid response. 1 for yes, 2 for no" << std::endl;
	     }	
	} 

     }	
};	



#endif