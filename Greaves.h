#ifndef GREAVES_H
#define GREAVES_H
#include <iostream>
#include "armor.h"
#include "player.h"

class Greaves : public Armor{
   private:
        int defense;
   public:
        Greaves(int i, std::string n, int d) : Armor(i, n, d) {
                defense =  d;
        }
        ~Greaves(); 
     virtual void increaseStats(Player* p1) {
                p1->defense += defense;
        }
};

#endif

