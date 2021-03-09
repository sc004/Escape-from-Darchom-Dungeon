#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <iostream>
#include <string>

using namespace std;
class Player;
class Encounter{
	private:
		int type;
	public:
		
		Encounter(int t){type = t;}
		~Encounter();{
			cout << "in encounter destructor\n";
		}
		int get_type(){
			return type;
		}
		virtual void run(Player*)=0;
};
#endif //ENCOUNTER_H
