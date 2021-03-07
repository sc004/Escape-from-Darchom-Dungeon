#ifndef ITEMGENERATE_H
#define ITEMGENERATE_H

#include <iostream>
#include <string>
#include "DoubleHealth.h"
#include "FullHealth.h"
#include "IncreaseSpeed.h"
#include "ChestPlate.h"
#include "Helmet.h"
#include "Greaves.h"
#include "sword.h"
#include "spear.h"
#include "bow.h"
#include "shield.h"
using namespace std;


class ItemGenerate {
	public:
		ItemGenerate();
		~ItemGenerate();
		
		item* makeItem(int id){
			int type = rand() % 3 + 1;
			string iName;
			if (type==1){
				iName="Basic ";
			}
			else if(type == 2){
				iName="Advanced ";
			}
			else if(type == 3){
				iName="Great ";
			}
			/*weapons*/
			if(id==1){
				return new sword(id, iName + "Sword", 10*type, 20*type);
			}
			else if(id==2){
				return new spear(id, iName + "Spear", 15*type, 22*type);
			}
			else if(id==3){
				return new shield(id, iName + "Shield", 2*type, 10*type);
			}
			else if(id==4){
				return new bow(id, iName + "Bow", 5*type, 21*type);
			}
			/*armors*/
			else if(id==5){
				return new ChestPlate(id, iName + "Chestplate", 3*type);
			}
			else if(id==6){
				return new Helment(id, iName + "Helmet", 2*type);
			}
			else if(id==7){
				return new Greaves(id, iName + "Greaves", 1*type);
			}
			/*potions*/
			else if(id==8){
				return new DoubleHealth(id, "Double Health Potion");
			}
			else if(id==9){
				return new FullHealth(id, "Full Health Potion");
			}
			else if(id==10){
				return new IncreaseSpeed(id, "IncreaseSpeed Potion");
			}
			else{
				return nullptr;
			}
		}
}

#endif //ITEMGENERATE_H
