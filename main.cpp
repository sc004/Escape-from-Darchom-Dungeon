#include "dungeon.h"
#include <iostream>

using namespace std;


int main(){

	dungeon* dungeon1 = new dungeon(0);
	dungeon1->generatePlayer();
	dungeon1->explore();
	
	return 0;
}

