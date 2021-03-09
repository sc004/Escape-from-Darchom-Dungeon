#ifndef FULL_HEALTH_H
#define FULL_HEALTH_H
#include <iostream>
#include "potion.h"
#include "player.h"
#include "item.h"
using namespace std;
class FullHealth : public Potion{
   public:
      FullHealth(int i, std::string n) : Potion(i, n) {}
        ~FullHealth(){}
        virtual void increaseStats(Player* p1) {
                if (p1->get_health() < p1->get_maxHealth()) {
                        p1->set_health(p1->get_maxHealth());
                        cout<< "You have been healed to full!"<<endl;
                }
        }
};

#endif

