#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Player;
class item{
	private:
		int itemID;
		string name;
	public:
		item(int id, string n){itemID = id; name = n;}
		~item();
		int get_itemID(){
			return itemID;
		}
		string get_name(){
			return name;
		}
		//armor functs
		virtual void set_isEquipped(bool equip){}
		virtual bool get_isEquiped(){return false;}
		virtual int get_defense(){return 0;}
		//armor and pot funct
		virtual void increaseStats(Player* p1){}
		//weapon functs
		virtual int get_advPoints(){return 0;}
		virtual int get_timesUsed(){return 0;}
		virtual int get_durability(){return 0;}
		virtual void increase_timesUsed(){}
		virtual int get_attack(){return 0;}
		
	

};
#endif //ITEM_H
