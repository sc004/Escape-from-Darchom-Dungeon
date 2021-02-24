
#ifndef FLOOR_H
#define FLOOR_H
#include <cmath>
#include "trap.h"
#include "player.h"


using namespace std;

class Floor_Trap: public Trap {
	private:
	int damage;

	public:
	Floor_Trap(int statusC): Trap(statusC){
		damage = 50;
	}
	~Floor_Trap();
	void attemptDisarm(Player* p1){
		int check = rand() % 100 + 1;
		
		if(check < 50){
			p1->health -= damage;
			p1->status = getStatus();
			p1->Add_Item(getItem());
		}else {
			p1->Add_Item(getItem());
		}		
	}

};

#endif
