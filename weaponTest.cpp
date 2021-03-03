#include <iostream>


#include "sword.h"
#include "spear.h"
#include "bow.h"
#include "shield.h"
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

TEST(BowTest, Constructor){
        bow* b1 = new bow(10, "Basic Bow", 5,200);
        EXPECT_EQ(b1->get_itemID(), 10);
}
TEST(BowTest, advPointTest){
        bow* b1 = new bow(10, "Basic Bow", 5,200);
        EXPECT_EQ(b1->get_advPoints(), 3);
}
TEST(BowTest, DurabilityTest){
        bow* b1 = new bow(10, "Basic Bow", 5,200);
		b1->increase_timesUsed();
        EXPECT_EQ(b1->get_durability(), 4);
}
TEST(BowTest, NameTest){
        bow* b1 = new bow(10, "Basic Bow", 5,200);
        EXPECT_EQ(b1->get_name(), "Basic Bow");
}

TEST(ShieldTest, Constructor){
        shield* s1 = new shield(20, "Basic Shield", 20,10);
        EXPECT_EQ(s1->get_itemID(), 20);
}
TEST(ShieldTest, advPointTest){
        shield* s1 = new shield(20, "Basic Shield", 20,10);
        EXPECT_EQ(s1->get_advPoints(), 0);
}
TEST(ShieldTest, DurabilityTest){
        shield* s1 = new shield(20, "Basic Shield", 20,10);
		s1->increase_timesUsed();
        EXPECT_EQ(s1->get_durability(), 19);
}
TEST(ShieldTest, NameTest){
        shield* s1 = new shield(20, "Basic Shield", 20,10);
        EXPECT_EQ(s1->get_name(), "Basic Shield");
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
