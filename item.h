#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;
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

};
#endif //ITEM_H
