#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "item.h"

#include <iostream>

class Player {
    private:
	int health;
	int attack;
	Item* currentWeapon;
	int defense;
	int speed;
	int <Item*> inventory;
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
	attack(Enemy* e){
		int health = enemy->get_hp();
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
	void AddItems(Item* i){
		inventory.push_back(i);
	}
	void UseItems(Item* i){
		if(i->get_ItemID() >=5 && item->get_itemID() <=7){
			i->increaseStats(this);
			i->set_isEquipped = true;
			cout << i->get_name() << " has been equipped" << endl;
		}else if(i->get_ItemID() <= 10 && i->get_ItemID() >= 8){
			i->increaseStats(this);
			for(int k = 0; k < inventory.size(); k++){
                        	if(i == inventory.at(k)){
                                	inventory.erase(inventory.begin()+k);
                        	}
                	}		
		
		}
	}
	void equipWeapon(Item* i){
		currentWeapon = i;
		attack += i->get_attack();
	}
	void unequipWeapon(Item* i){
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
};

#endif //__PLAYER_HPP__
