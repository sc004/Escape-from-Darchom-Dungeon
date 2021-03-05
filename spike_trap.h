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
				cout << "Spike Trap was not successfully disarmed. You took damage and are not bleeding" << endl;
				p1->set_health(p1->get_health() - damage);
				p1->set_status(getStatus());
				p1->AddItems(getItem());
			}else{
				cout << "Spike Trap was successfully disarmed" <<endl;
				p1->AddItems(getItem());
			}
		}
};

#endif	
