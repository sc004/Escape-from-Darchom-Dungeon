#ifndef DOUBLE_HEALTH_H
#define DOUBLE_HEALTH_H
#include <iostream>
#include "potion.h"
#include "player.h"
#include "item.h"

class DoubleHealth : public Potion{
   public:
      DoubleHealth(int i, std::string n) : Potion(i, n) {}
        ~DoubleHealth();
        virtual void increaseStats(Player* p1) {
                        p1->maxHealth *=2;
                        p1->health *= 2;
        }
};

#endif

