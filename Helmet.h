#ifndef HELMET_H
#define HELMET_H
#include <iostream>
#include "armor.h"
#include "player.h"

class Helmet : public Armor{
   private:
        int defense;
   public:
        Helmet(int i, std::string n, int d) : Armor(i, n, d) {
                defense =  d;
        }
        ~Helmet();
        virtual void increaseStats(Player* p1) {
                p1->defense += defense;
        }
};

#endif

