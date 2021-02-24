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
				p1->health -= damage;
				p1->Add_Item(getItem());
			}else{
				p1->Add_Item(getItem());
			}
		}
};

#endif