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
	void attemptDisarm(Player*){
		int check = rand() % 100 + 1;
		
		if(check < 50){
			Player->health -= damage;
			Player->status = this->getStatus();A
		}else {
			Player->Add_Item(this->getItem());
		}		
	}

};
