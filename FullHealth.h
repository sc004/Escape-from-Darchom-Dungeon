#ifndef FULL_HEALTH_H
#define FULL_HEALTH_H
#include <iostream>
#include "potion.h"
#include "player.h"
#include "item.h"

class FullHealth : public Potion{
   public:
      FullHealth(int i, std::string n) : Potion(i, n) {}
        ~FullHealth();
        virtual void increaseStats(Player* p1) {
                if (p1->get_health() < 100) {
                        p1->health = 100;
                }
        }
};

#endif

