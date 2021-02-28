#include "armor.h"
#include"player.h"
#include "gtest/gtest.h"
#include "ChestPlate.h"
#include "Helmet.h"
#include "Greaves.h"

TEST(ChestPlateTest, getDefense) {
	ChestPlate* c = new ChestPlate(1, "ChestPlate", 3);
		EXPECT_EQ(c->get_defense(), 3);
}

TEST(ChestPlateTest, getID) {
        ChestPlate* c = new ChestPlate(1, "ChestPlate", 3);
                EXPECT_EQ(c->get_itemID(), 1);
}

TEST(ChestPlateTest, getName) {
        ChestPlate* c = new ChestPlate(1, "ChestPlate", 3);
                EXPECT_EQ(c->get_name(), "ChestPlate");
}

TEST(ChestPlateTest, IncreaseStats) {
        ChestPlate* c = new ChestPlate(1, "ChestPlate", 3);
	Player* p1 = new Player();
	c->increaseStats(p1);
                EXPECT_EQ(p1->get_defense(), 13);
}

TEST(HelmetTest, getDefense) {
        Helmet* h = new Helmet(2, "Helmet", 4);
        EXPECT_EQ(h->get_defense(), 4);
}

TEST(HelmetTest, getID) {
        Helmet* h = new Helmet(2, "Helmet", 4);
                EXPECT_EQ(h->get_itemID(), 2);
}

TEST(HelmetTest, getName) {
        Helmet* h = new Helmet(2, "Helmet", 4);
                EXPECT_EQ(h->get_name(), "Helmet");
}


TEST(HelmetTest, IncreaseStats) {
        Helmet* h = new Helmet(2, "helmet", 4);
        Player* p1 = new Player();
        h->increaseStats(p1);
        EXPECT_EQ(p1->get_defense(), 14);
}

TEST(GreavesTest, getDefense) {
        Greaves* g = new Greaves(3, "Greaves", 2);
        EXPECT_EQ(g->get_defense(), 2);
}

TEST(GreavesTest, getID) {
        Greaves* g = new Greaves(3, "Greaves", 2);
        EXPECT_EQ(g->get_itemID(), 3);
}

TEST(GreavesTest, getName) {
        Greaves* g = new Greaves(3, "Greaves", 2);
                EXPECT_EQ(g->get_name(), "Greaves");
}

TEST(GreavesTest, IncreaseStats) {
        Greaves* g = new Greaves(3, "Greaves", 2);
        Player* p1 = new Player();
        g->increaseStats(p1);
        EXPECT_EQ(p1->get_defense(), 12);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

