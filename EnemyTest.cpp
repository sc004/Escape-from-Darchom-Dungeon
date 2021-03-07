#include <iostream>
#include "item.h"
#include "Enemy.hpp"
#include "Goblin.hpp"
#include "Troll.hpp"
#include "Wizard.hpp"
#include "player.h"
#include "gtest/gtest.h"

TEST(GoblinTest, Constructor) {
	item* w = new item(12, "weapon");
	item* l = new item(15, "loot");
	Goblin* g = new Goblin(7, 2, 3, 5, 1, "goblin", w, l);
	EXPECT_EQ(g->get_name(), "goblin");
	 EXPECT_EQ(g->get_hp(), 7);
	 EXPECT_EQ(g->get_attack(), 2);
	 EXPECT_EQ(g->get_defense(), 3);
	 EXPECT_EQ(g->get_speed(), 5);
	 EXPECT_EQ(g->get_weakness(), 1);
}

TEST(GoblinTest, useSlash) {
	item* w = new item(12, "weapon");
        item* l = new item(15, "loot");
        Goblin* g = new Goblin(7, 2, 3, 5, 1, "goblin", w, l);
	Player* p1 = new Player(100, 60, 50, 50);
	p1->set_health(g->useSlash(p1->get_health(), p1->get_defense()));
	EXPECT_EQ(p1->get_health(), 88);
}

TEST(GoblinTest, useStab) {
        item* w = new item(12, "weapon");
        item* l = new item(15, "loot");
        Goblin* g = new Goblin(7, 2, 3, 5, 1, "goblin", w, l);
        Player* p1 = new Player(100, 60, 50, 50);
        p1->set_health(g->useStab(p1->get_health(), p1->get_defense()));
        EXPECT_EQ(p1->get_health(), 90);
}

TEST(TrollTest, Constructor) {
       item* w = new item(12, "weapon"); 
       item* l = new item(15, "loot");
       Troll* t = new Troll(7, 2, 3, 5, 1, "troll", w, l);
       EXPECT_EQ(t->get_name(), "troll");
       EXPECT_EQ(t->get_hp(), 7);
       EXPECT_EQ(t->get_attack(), 2);
       EXPECT_EQ(t->get_defense(), 3);
       EXPECT_EQ(t->get_speed(), 5);
       EXPECT_EQ(t->get_weakness(), 1);
}

TEST(TrollTest, useSwipe) {
        item* w = new item(12, "weapon");
        item* l = new item(15, "loot");
        Troll* t = new Troll(7, 2, 3, 5, 1, "troll", w, l);
        Player* p1 = new Player(100, 60, 50, 50);
        p1->set_health(t->useSwipe(p1->get_health(), p1->get_defense()));
        EXPECT_EQ(p1->get_health(), 90);
}

TEST(TrollTest, useSlam) {
        item* w = new item(12, "weapon");
        item* l = new item(15, "loot");
        Troll* t = new Troll(7, 2, 3, 5, 1, "troll", w, l);
        Player* p1 = new Player(100, 60, 50, 50);
        p1->set_health(t->useSlam(p1->get_health(), p1->get_defense()));
        EXPECT_EQ(p1->get_health(), 94);
}


TEST(WizardTest, Constructor) {
        item* wp = new item(12, "weapon");
        Wizard* w = new Wizard(7, 2, 3, 5, 1, "wizard", wp);
        EXPECT_EQ(w->get_name(), "wizard");
        EXPECT_EQ(w->get_hp(), 7);
        EXPECT_EQ(w->get_attack(), 2);
        EXPECT_EQ(w->get_defense(), 3);
        EXPECT_EQ(w->get_speed(), 5);
        EXPECT_EQ(w->get_weakness(), 1);
}

TEST(WizardTest, useFireball) {
        item* wp = new item(12, "weapon");
        Wizard* w = new Wizard(7, 2, 3, 5, 1, "wizard", wp);
        Player* p1 = new Player(100, 60, 50, 50);
        p1->set_health(w->useFireball(p1->get_health(), p1->get_defense()));
        EXPECT_EQ(p1->get_health(), 82);
}

TEST(WizardTest, useLightning) {
        item* wp = new item(12, "weapon");
       	Wizard* w = new Wizard(7, 2, 3, 5, 1, "wizard", wp);
        Player* p1 = new Player(100, 60, 50, 50);
        p1->set_health(w->useLightning(p1->get_health(), p1->get_defense()));
        EXPECT_EQ(p1->get_health(), 86);
}

TEST(WizardTest, useMagicMissile) {
	item* wp = new item(12, "weapon");
	Wizard* w = new Wizard(7, 2, 3, 5, 1, "wizard", wp);
	Player* p1 = new Player(100, 60, 50, 50);
	p1->set_health(g->useMagicMissle(p1->get_health(), p1->get_defense()));
	EXPECT_EQ(p1->get_health(), 90);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
