
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
		int chance = rand() % 100 + 1;
		if(chance < 50){
                                cout << "Floor Trap was not successfully disarmed. You took " << damage << " damage";
                                if(!p1->hasStatus()){
                                        cout << " and are now crippled" << endl;
                                        p1->set_status(3);
                                        p1->set_Counter(5);
                                }else{
					p1->set_Counter(p1->get_Counter() + 5);
                                        cout << endl;
                                }
                                p1->set_health(p1->get_health() - damage);
                                p1->AddItems(getItem());
                        }else{
                                cout << "Floor Trap was successfully disarmed" <<endl;
                                p1->AddItems(getItem());
                        }
		
	}

};

#endif
