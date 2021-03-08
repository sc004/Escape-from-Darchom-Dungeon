#ifndef DART_H
#define DART_H

#include <cmath>
#include "player.h"
#include "trap.h" //dunno if this is needed

using namespace std;

class Dart_Trap : public Trap{
	private:
		int damage;
	public:
		Dart_Trap(int StatusC): Trap(StatusC){
			damage = 25;
		}
		~Dart_Trap();
		void attemptDisarm(Player* p1){
			int chance = rand() % 100 + 1;
			if(chance < 50){
				cout << "You did not successfully disarm the Dart Trap. You took " << damage << " and are now poisoned" << endl;
				p1->set_health(p1->get_health() - damage);
				p1->AddItems(getItem());
			}else{
				cout << "Dart Trap was successfully disarmed." << endl;
				p1->AddItems(getItem());
			}
		}
};

#endif
