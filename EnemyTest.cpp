#include <iostream>
#include "Item.hpp"
#include "Enemy.hpp"
#include "Goblin.hpp"
#include "Troll.hpp"
#include "Wizard.hpp"
#include "Player.hpp"
#include "gtest/gtest.h"

TEST(GoblinTest, Constructor) {
	Item* w = new Item(12, "weapon");
	Item* l = new Item(15, "loot");
	Goblin* g = new Goblin(7, 2, 3, 5, 1, "goblin", w, l);
	EXPECT_EQ(g->get_name(), "goblin");
	 EXPECT_EQ(g->get_hp(), 7);
	 EXPECT_EQ(g->get_attack(), 2);
	 EXPECT_EQ(g->get_defense(), 3);
	 EXPECT_EQ(g->get_speed(), 5);
	 EXPECT_EQ(g->get_weakness(), 1);
}

TEST(GoblinTest, useSlash) {
	 Item* w = new Item(12, "weapon");
        Item* l = new Item(15, "loot");
        Goblin* g = new Goblin(7, 2, 3, 5, 1, "goblin", w, l);
	Player* p1 = new Player();
	g->useSlash(p1);
	EXPECT_EQ(p1->get_health(), 8);
}

TEST(GoblinTest, useStab) {
         Item* w = new Item(12, "weapon");
        Item* l = new Item(15, "loot");
        Goblin* g = new Goblin(7, 2, 3, 5, 1, "goblin", w, l);
        Player* p1 = new Player();
        g->useStab(p1);
        EXPECT_EQ(p1->get_health(), 5);
}

TEST(TrollTest, Constructor) {
        Item* w = new Item(12, "weapon");
        Item* l = new Item(15, "loot");
        Troll* t = new Troll(7, 2, 3, 5, 1, "troll", w, l);
        EXPECT_EQ(t->get_name(), "troll");
         EXPECT_EQ(t->get_hp(), 7);
         EXPECT_EQ(t->get_attack(), 2);
         EXPECT_EQ(t->get_defense(), 3);
         EXPECT_EQ(t->get_speed(), 5);
         EXPECT_EQ(t->get_weakness(), 1);
}

TEST(TrollTest, useSwipe) {
         Item* w = new Item(12, "weapon");
        Item* l = new Item(15, "loot");
        Troll* t = new Troll(7, 2, 3, 5, 1, "troll", w, l);
        Player* p1 = new Player();
        t->useSwipe(p1);
        EXPECT_EQ(p1->get_health(), 8);
}

TEST(TrollTest, useSlam) {
         Item* w = new Item(12, "weapon");
        Item* l = new Item(15, "loot");
        Troll* t = new Troll(7, 2, 3, 5, 1, "troll", w, l);
        Player* p1 = new Player();
        t->useSlam(p1);
        EXPECT_EQ(p1->get_health(), 9);
}


TEST(WizardTest, Constructor) {
        Item* wp = new Item(12, "weapon");
         Wizard* w = new Wizard(7, 2, 3, 5, 1, "wizard", wp);
        EXPECT_EQ(w->get_name(), "wizard");
         EXPECT_EQ(w->get_hp(), 7);
         EXPECT_EQ(w->get_attack(), 2);
         EXPECT_EQ(w->get_defense(), 3);
         EXPECT_EQ(w->get_speed(), 5);
         EXPECT_EQ(w->get_weakness(), 1);
}

TEST(WizardTest, useFireball) {
         Item* wp = new Item(12, "weapon");
         Wizard* w = new Wizard(7, 2, 3, 5, 1, "wizard", wp);
        Player* p1 = new Player();
        w->useFireball(p1);
        EXPECT_EQ(p1->get_health(), 3);
}

TEST(WizardTest, useLightning) {
         Item* wp = new Item(12, "weapon");
       	Wizard* w = new Wizard(7, 2, 3, 5, 1, "wizard", wp);
        Player* p1 = new Player();
        w->useLightning(p1);
        EXPECT_EQ(p1->get_health(), 5);
}

TEST(WizardTest, useMagicMissile) {
	Item* wp = new Item(12, "weapon");
	Wizard* w = new Wizard(7, 2, 3, 5, 1, "wizard", wp);
	Player* p1 = new Player();
	w->useMagicMissle(p1);
	EXPECT_EQ(p1->get_health(), 6);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
