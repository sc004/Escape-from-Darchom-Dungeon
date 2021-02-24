#ifndef TRAP_H
#define TRAP_H

#include "item.h"
#include "potion.h"
#include "player.h"


class Trap{
	private:
		int statusCaused;
		Potion* pot;
		
	public:
		Trap(int statusC){
			statusCaused = statusC;
			pot = new Potion(1,"kekPotion");
		}
		~Trap();
		Potion* getItem(){
			return pot;
		}
		int getStatus(){
			return statusCaused; 
		}
};

#endif
