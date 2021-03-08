#include "dungeon.h"
#include <iostream>
#include "Item_Encounter.h"
#include "encounter.h"
#include "trapEncounter.h"
#include "enemyencounter.h"
#include "level.h"
using namespace std;


int main(){

	dungeon* dungeon1 = new dungeon(0);
	dungeon1->generatePlayer();
	dungeon1->explore();
	
	return 0;
}

