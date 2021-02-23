#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;
class item{
	private:
		int itemID=0;
		string name="CHANGE";
	public:
		item();
		~item();
		int get_itemID(){
			return itemID;
		}
		string get_name(){
			return name;
		}

};
#endif //ITEM_H
