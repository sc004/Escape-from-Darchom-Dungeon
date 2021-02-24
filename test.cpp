#include "trap.h"
#include "player.h" //<- let's pretend that's there
#include "spike_trap.h"
#include "floor_trap.h"
#include "dart_trap.h"
#include "gtest/gtest.h"

TEST(FloorTest, Constructor){
	Floor_Trap* test = new Floor_Trap(2);
	EXPECT_EQ(test->getStatus(),2);
}

TEST(SpikeTest, Constructor){
	Spike_Trap* test = new Spike_Trap(3);
	EXPECT_EQ(test->getStatus(),3);
}

TEST(DartTest, Constructor){
	Dart_Trap* test = new Dart_Trap(1);
	EXPECT_EQ(test->getStatus(),1);
}

TEST(FloorTest, testGotItem){
	Floor_Trap* test = new Floor_Trap(2);
	Player* p1 = new Player();
	test->attemptDisarm(p1);
	EXPECT_EQ(p1->gotItem,true); 
}

TEST(SpikeTest, testGotItem){
	Spike_Trap* test = new Spike_Trap(3);
	Player* p1 = new Player();
	test->attemptDisarm(p1);
	EXPECT_EQ(p1->gotItem,true);	
}

TEST(DartTest, testGotItem){
	Dart_Trap* test = new Dart_Trap(1);
	Player* p1 = new Player();
	test->attemptDisarm(p1);
	EXPECT_EQ(p1->gotItem,true);
}



int main(int argc, char**argv){
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
