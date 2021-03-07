#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__
#include <stdio.h>
#include "item.h"
#include "Enemy.hpp"
#include "armor.h"
#include "potion.h"
#include "weapon.h"
#include <iostream>
#include <vector>
class Player {
    private:
	int health;
	int attack;
	weapon* currentWeapon;
	int defense;
	int speed;
	vector<item*> inventory;
	int status;
	bool blocking;
	int maxHealth;
        
    public:
       	Player(int health, int attack, int defense, int speed){
		health = 100;
		attack = 60;
		defense = 50;
		speed = 50;
		maxHealth = health;
	}
	void attackEnemey(Enemy* e){
		int health = e->get_hp();
		if(this->currentWeapon->get_advPoints() == e->get_weakness()){
			cout << "A Critical hit!" << endl;
			cout << "You dealt " << to_string(attack*2) << "damage to " << e->get_name() << "!\n";	
			health -= (this->attack*2);
			e->set_hp(health);
		}else{
			cout << "You dealt " << attack << "damage to " << e->get_name() << "!\n";
			health -= (this->attack);
			e->set_hp(health);
		}
	}
	void AddItems(item* i){
		inventory.push_back(i);
	}
	void UseItems(item* i){
		if(i->get_itemID() >=5 && i->get_itemID() <=7){
			Armor* a = new ChestPlate(0,"",1);
			memcpy(&a,&i,sizeof(*i));
			a->increaseStats(this);
			a->set_isEquiped() = true;
			cout << i->get_name() << " has been equipped" << endl;
			delete a;
		}else if(i->get_itemID() <= 10 && i->get_itemID() >= 8){
			Potion*  p = new Potion(5,"2xHealth");
			memcopy(&p,&i,sizeof(*i));
			p->increaseStats(this);
			for(int k = 0; k < inventory.size(); k++){
                        	if(i == inventory.at(k)){
                                	inventory.erase(inventory.begin()+k);
                        	}
                	}		
			delete p;
		}
	}
	void equipWeapon(item* i){
		if(i->get_durability() <= 0){
			cout << "Hey Idiot! Your weapon is broken! Switch to another one" << endl;
		}else {
			currentWeapon = i;
			attack += i->get_attack();
		}
	}
	void unequipWeapon(item* i){
		attack -= i->get_attack();
		currentWeapon = nullptr;
	}
	void displayInventory(){
		int count = 1;
		for(i = 0; i < inventory.size(); i++){
			cout << to_string(count) << ") " <<  inventory.at(i)->get_name() << endl;
			count++;
		}	
	}

	void displayPlayerStats(){
		cout << << "health: " to_string(health) << " " << "attack: " to_string(attack) << " " << "defense " to_string(defense) << "speed: " to_string(speed) << " " << "current status : " << to_string(status);
	}
	int get_health() {return health;}
	int get_defense() {return defense;}
	int get_speed() {return speed;}
	int get_attack() {return attack;}
};

#endif //__PLAYER_HPP__
