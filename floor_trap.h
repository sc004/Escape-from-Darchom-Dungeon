
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
			cout << "You did not successfuly disarm the FloorTrap. You took damage and you are now crippled" << endl;
			p1->health -= damage;
			p1->status = getStatus();
			p1->Add_Item(getItem());
		}else {
			cout << "You successfully disarmed the FloorTrap. You got a potion!" << endl;
			p1->Add_Item(getItem());
		}		
	}

};

#endif
