CMAKE_MINIMUM_REQUIRED(VERSION 2.8)


SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(WeaponTest
	weaponTest.cpp
)

ADD_EXECUTABLE(EnemyTest
	EnemyTest.cpp
)

ADD_EXECUTABLE(ArmorTest
	armorTest.cpp
)

ADD_EXECUTABLE(PotionTest
	PotionTest.cpp
)

ADD_EXECUTABLE(PlayerTest
	playerTest.cpp
)

TARGET_LINK_LIBRARIES(WeaponTest gtest)
TARGET_COMPILE_DEFINITIONS(WeaponTest PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(EnemyTest gtest)
TARGET_COMPILE_DEFINITIONS(EnemyTest PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(ArmorTest gtest)
TARGET_COMPILE_DEFINITIONS(ArmorTest PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(PotionTest gtest)
TARGET_COMPILE_DEFINITIONS(PotionTest PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(PlayerTest gtest)
TARGET_COMPILE_DEFINITIONS(PlayerTest PRIVATE gtest_disable_pthreads=ON)
