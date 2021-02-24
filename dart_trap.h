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
		void attemptDisarm(Player*){
			int chance = rand() % 100 + 1;
			if(chance < 50){
				Player->status = this->getStatus();
				Player->health -= damage;
			}else{
				Player->Add_Item(this->getItem());
			}
		}
};
