#ifndef TRAP_ENCOUNTER_H
#define TRAP_ENCOUNTER_H

#include "encounter.h"
#include "trap.h"
#include "player.h"


class Trap_Encounter : public Encounter{
	private:
		Trap* trapEncountered;
		bool hasDisarmed;
	public:
		Trap_Encounter(int t): Encounter(t){
			int generate = (rand() % 3) + 1;
			
			if(generate == 1){
			trapEncountered = new Spike_Trap(1);
			}
			if(generate == 2){
			trapEncountered = new Floor_Trap(2);
			}
			if(generate == 3){
			trapEncountered = new Dart_Trap(3);
			}
		}
		~Trap_Encounter(){}
		void askToDisarm(Player* p){
			bool done = false;
			char option;
			cout << "Would you like to disarm the trap? 1 for yes, 2 for no" << endl;

			while(done == false){
			cin << option;
				if(option != '1' || option != '2'){
					cout << "Please enter a valid response" << endl;
				}else if(option == '1'){
					cout << "Player attempted to disarm the trap" << endl;
					trapEncountered->attemptDisarm(p);
					hasDisarmed = true;
					done = true;
					
				}else if(option == '2'){
					cout << "Player decided not to disarm the trap" << endl;	
					hasDisarmed = false;
					done = true;
				}
				
			
			}	


#endif
