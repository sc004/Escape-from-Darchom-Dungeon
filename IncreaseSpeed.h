#ifndef INCREASE_SPEED_H
#define INCREASE_SPEED_H
#include <iostream>
#include "potion.h"
#include "player.h"
#include "item.h"

class IncreaseSpeed : public Potion{
   public:
      IncreaseSpeed(int i, std::string n) : Potion(i, n) {}
        ~IncreaseSpeed();
        virtual void increaseStats(Player* p1) {
               p1->speed *= 2;
               cout<< "Your speed has doubled!"<<endl;
        }
};

#endif

