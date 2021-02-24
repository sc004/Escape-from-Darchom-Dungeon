#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <iostream>

class Item {
    private:
        int itemID;
        std::string name;
    public:
        Item(int id, std::string n) {
            itemID = id;
            name = n;
        }
	~Item();
        int get_itemID() {
            return itemID;
        }
        std::string get_name() {
            return name;
        }
};

#endif // __ITEM_HPP__
