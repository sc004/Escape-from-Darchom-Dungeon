#ifndef TRAP_H
#define TRAP_H

#include "item.h"
#include "potion.h"
#include "player.h"
#include "FullHealth.h"

class Trap{
	private:
		int statusCaused;
		Potion* pot;
		
	public:
		Trap(int statusC){
			statusCaused = statusC;
			pot  = new FullHealth(9, "FullHealth Potion");
		}
		~Trap(){
			if(pot !=NULL|| pot != nullptr){
                        	delete pot;
                	}
		}
		Potion* getItem(){
			Potion* temp= pot;
                	pot = nullptr;
                	return temp;
		}
		int getStatus(){
			return statusCaused; 
		}
		virtual void attemptDisarm(Player* p1)=0;
};

#endif
