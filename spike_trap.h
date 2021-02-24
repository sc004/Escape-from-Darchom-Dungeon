#ifndef SPIKE_H
#define SPIKE_H

#include <cmath>
#include "player.h"
#include "item.h"
#include "trap.h"


class Spike_Trap: public Trap{
	private:
		int damage;
	public:
		Spike_Trap(int statusC): Trap(statusC){
			damage = 60;
		}
		~Spike_Trap();
		virtual void attemptDisarm(Player* p1){
			int chance = rand() % 100 + 1;
			if(chance < 50){
				p1->health -= damage;
				p1->status = getStatus();
				p1->Add_Item(getItem());
			}else{
				p1->Add_Item(getItem());
			}
		}
};

#endif	
