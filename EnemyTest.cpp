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
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
