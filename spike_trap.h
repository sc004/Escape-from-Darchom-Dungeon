#include <cmath>
#include "player.h"
#include "item.h"
#include "trap.h"


class Spike_Trap: public Trap{
	private:
		int damage;
	public:
		Spike_Trap(int statusC): Trap(StatusC){
			damage = 60;
		}
		~Spike_Trap();
		virtual void attempDisarm(Player*){
			int chance = rand() % 100 + 1;
			if(chance < 50){
				Player->health -= damage;
				Player->status = this->getStatus();
			}else{
				Player->Add_Items(this->getItem());
			}
		}
};	
