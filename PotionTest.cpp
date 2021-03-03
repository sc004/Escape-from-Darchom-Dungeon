#include "potion.h"
#include"player.h"
#include "gtest/gtest.h"
#include "DoubleHealth.h"
#include "FullHealth.h"
#include "IncreaseSpeed.h"

TEST(DoubleHealthTest, getID) {
        DoubleHealth* h = new DoubleHealth(1, "DoubleHealth");
                EXPECT_EQ(h->get_itemID(), 1);
} 

TEST(DoubleHealthTest, getName) {
        DoubleHealth* h = new DoubleHealth(1, "DoubleHealth");
        EXPECT_EQ(h->get_name(), "DoubleHealth");
}


TEST(DoubleHealthTest, IncreaseStats) {
        DoubleHealth* h = new DoubleHealth(1, "DoubleHealth");
	Player* p1 = new Player();
	p1->health = 50;
	h->increaseStats(p1);
        EXPECT_EQ(p1->get_health(), 100);
}

TEST(DoubleHealthTest, NoIncreaseStats) {
        DoubleHealth* h = new DoubleHealth(1, "DoubleHealth");
        Player* p1 = new Player();
        h->increaseStats(p1);
        EXPECT_EQ(p1->get_health(), 100);
}

TEST(FullHealthTest, getID) {
        FullHealth* h = new FullHealth(2, "FullHealth");
        EXPECT_EQ(h->get_itemID(), 2);
}

TEST(FullHealthTest, getName) {
        FullHealth* h = new FullHealth(2, "FullHealth");
        EXPECT_EQ(h->get_name(), "FullHealth");
}


TEST(FullHealthTest, IncreaseStats) {
        FullHealth* h = new FullHealth(2, "FullHealth");
        Player* p1 = new Player();
        p1->health = 60;
        h->increaseStats(p1);
        EXPECT_EQ(p1->get_health(), 100);
}

TEST(FullHealthTest, NoIncreaseStats) {
        FullHealth* h = new FullHealth(2, "FullHealth");
        Player* p1 = new Player();
        h->increaseStats(p1);
        EXPECT_EQ(p1->get_health(), 100);
}

TEST(IncreaseSpeedTest, getID) {
        IncreaseSpeed* h = new IncreaseSpeed(3, "IncreaseSpeed");
        EXPECT_EQ(h->get_itemID(), 3);
}

TEST(IncreaseSpeedTest, getName) {
        IncreaseSpeed* h = new IncreaseSpeed(3, "IncreaseSpeed");
        EXPECT_EQ(h->get_name(), "IncreaseSpeed");
}


TEST(IncreaseSpeedTest, IncreaseStats) {
        IncreaseSpeed* h = new IncreaseSpeed(3, "IncreaseSpeed");
        Player* p1 = new Player();
        h->increaseStats(p1);
        EXPECT_EQ(p1->get_speed(), 5);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
