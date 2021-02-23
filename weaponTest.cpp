#include <iostream>

#include "sword.h"
#include "gtest/gtest.h"

using namespace std;

TEST(SwordTest, Constructor){
	sword s1 = new sword(1, 10, "Basic Sword", 100);
	EXPECT_EQ(s1->get_itemID, 1);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
