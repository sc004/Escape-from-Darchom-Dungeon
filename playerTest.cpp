#include "player.h"
#include "gtest/gtest.h"
#include "potion.h"
#include "spear.h"
#include "sword.h"
#include "ChestPlate.h"
#include "knife.h"
#include "item.h"
#include "bow.h"
#include "Enemy.hpp"
#include "FullHealth.h"
#include "Goblin.hpp"
#include <string>

using namespace std;

TEST(PlayerTest, getHealth){
	int health = 0;
	int attack = 0;
	int defense = 0;
	int speed = 0;
	Player* p1 = new Player(health, attack, defense, speed);
	EXPECT_EQ(p1->get_health(), 100);
}

TEST(PlayerTest, getDefense){
        int health = 0;
        int attack = 0;
        int defense = 0;
        int speed = 0;
        Player* p1 = new Player(health, attack, defense, speed);
        EXPECT_EQ(p1->get_defense(),50);
}

TEST(PlayerTest, getSpeed){
        int health = 0;
        int attack = 0;
        int defense = 0;
        int speed = 0;
        Player* p1 = new Player(health, attack, defense, speed);
        EXPECT_EQ(p1->get_speed(),50);
}

TEST(PlayerTest, getAttack){
        int health = 0;
        int attack = 0;
        int defense = 0;
        int speed = 0;
        Player* p1 = new Player(health, attack, defense, speed);
        EXPECT_EQ(p1->get_attack(),60);
}

TEST(PlayerTest, addItemsPotion){
	int health = 0;
	int attack = 0;
	int defense = 0;
	int speed = 0;
	Player* p1 = new Player(health, attack, defense, speed);
	item* pot = new FullHealth(9, "FullHealth");
	p1->AddItems(pot);
	EXPECT_EQ(p1->inventory.at(0)->get_itemID(),9);

}

TEST(PlayerTest, additemsArmor){
	int health = 0;
	int attack = 0;
	int defense = 0;
	int speed = 0;
	Player* p1 = new Player(health, attack, defense, speed);
	ChestPlate* test = new ChestPlate(5, "ChestPlate", 69);
	p1->AddItems(test);
	item* tester = p1->inventory.at(0);
	EXPECT_EQ(tester->get_itemID(),5);	
}

TEST(PlayerTest, useItemPotion){
	int health = 0;
	int attack = 0;
	int defense = 0;
	int speed = 0;
	Player* p1 = new Player(health, attack, defense, speed);
	item* pot = new FullHealth(9, "FullHealth");
	p1->UseItems(pot);
	EXPECT_EQ(p1->get_health(),100);	
}

TEST(PlayerTest, attackEnemyAdvantage){
	int health = 0;
	int attack = 0;
	int defense = 0;
	int speed = 0;
	Player* p1 = new Player(health, attack, defense, speed);
	sword* s = new sword(1,"Sword",34,20);
	p1->AddItems(s);
	p1->equipWeapon(s);
	int hp = 200;
	int attack1 = 40;
	int defense1 = 20;
	int speed1 = 60;
	int weakness = 1;
	string name = "Bradley Morck";
	Knife* k = new Knife();
	item* pot = new FullHealth(9, "FullHealth");
	Goblin* e = new Goblin(hp,attack1,defense1,speed1,weakness,name,k,pot);
	p1->attack(e);
	EXPECT_EQ(e->get_hp(),40);
}

TEST(PlayerTest, attackEnemyNoAdvantage){
        int health = 0;
        int attack = 0;
        int defense = 0;
        int speed = 0;
        Player* p1 = new Player(health, attack, defense, speed);
        spear* s = new spear(2,"Spear",34,22);
        p1->AddItems(s);
        p1->equipWeapon(s);
        int hp = 140;
        int attack1 = 40;
        int defense1 = 20;
        int speed1 = 60;
        int weakness = 1;
        string name = "Bradley Morck";
        Knife* k = new Knife();
        item* pot = new FullHealth(9,"FullHealth");
        Goblin* e = new Goblin(hp,attack1,defense1,speed1,weakness,name,k,pot);
        p1->attack(e);
        EXPECT_EQ(e->get_hp(),58);
}

TEST(PlayerTest, testEquipWeapon){
	int health = 0;
	int attack = 0;
	int defense = 0;
	int speed = 0;
	Player* p1 = new Player(health, attack, defense, speed);
	int id = 4;
	string n = "Base Bow";
	int dur = 5;
	int atk = 21;
	bow* b = new bow(id,n,dur,atk);
	p1->equipWeapon(b);
	EXPECT_EQ(p1->get_attack(),81);
}

TEST(PlayerTest, testEquipMultipleWeapons){
	int health;
	int attack;
	int defense;
	int speed = 0;
	Player* p1 = new Player(health, attack, defense, speed);
	int id = 1;
	string n = "Base Sword";
	int dur = 10;
	int atk = 20;
	sword* s = new sword(id,n,dur,atk);
	p1->equipWeapon(s);
	p1->unequipWeapon(s);
	int id2 = 4;
	string n2 = "Base Bow";
	int dur2 = 5;
	int atk2 = 21;
	bow* b = new bow(id2,n2,dur2,atk2);
	p1->equipWeapon(b);
	EXPECT_EQ(p1->get_attack(),81);
	
}

TEST(PlayerTest, testUnequipWeapon){
        int health = 0;
        int attack = 0;
        int defense = 0;
        int speed = 0;
        Player* p1 = new Player(health, attack, defense, speed);
        int id = 4;
        string n = "Base Bow";
        int dur = 5;
        int atk = 21;
        bow* b = new bow(id,n,dur,atk);
	p1->equipWeapon(b);
        p1->unequipWeapon(b);
        EXPECT_EQ(p1->get_attack(),60);
}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
};
