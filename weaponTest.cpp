#include <iostream>


#include "sword.h"
#include "spear.h"

#include "gtest/gtest.h"

using namespace std;

TEST(SwordTest, Constructor){
	sword* s1 = new sword(1, "Basic Sword", 10,100);
	EXPECT_EQ(s1->get_itemID(), 1);
}
TEST(SwordTest, advPointTest){
        sword* s1 = new sword(1, "Basic Sword", 10,100);
        EXPECT_EQ(s1->get_advPoints(), 1);
}
TEST(SwordTest, DurabilityTest){
        sword* s1 = new sword(1, "Basic Sword", 10,100);
		s1->increase_timesUsed();
        EXPECT_EQ(s1->get_durability(), 9);
}
TEST(SwordTest, NameTest){
        sword* s1 = new sword(1, "Basic Sword", 10,100);
        EXPECT_EQ(s1->get_name(), "Basic Sword");
}

TEST(SpearTest, Constructor){
        spear* s1 = new spear(3, "Basic Spear", 25,150);
        EXPECT_EQ(s1->get_itemID(), 3);
}
TEST(SpearTest, advPointTest){
        spear* s1 = new spear(3, "Basic Spear", 10,150);
        EXPECT_EQ(s1->get_advPoints(), 2);
}
TEST(SpearTest, DurabilityTest){
        spear* s1 = new spear(3, "Basic Spear", 10,150);
		s1->increase_timesUsed();
        EXPECT_EQ(s1->get_durability(), 9);
}
TEST(SpearTest, NameTest){
        spear* s1 = new spear(3, "Basic Spear", 10,150);
        EXPECT_EQ(s1->get_name(), "Basic Spear");
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
