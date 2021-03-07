#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "item.h"
#include "Enemy.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Player {
    private:
	int health;	
	int _attack;
	item* currentWeapon;
	int defense;
	int speed;
	vector <item*> inventory;
	int status;
	bool blocking;
	int maxHealth;
        
    public:
       	Player(int health, int attack, int defense, int speed){
		health = 100;
		_attack = 60;
		defense = 50;
		speed = 50;
		maxHealth = health;
	}
	void attack(Enemy* e){
		int health = e->get_hp();
		if(this->currentWeapon->get_advPoints() == e->get_weakness()){
			cout << "A Critical hit!" << endl;
			cout << "You dealt " << to_string(_attack*2) << "damage to " << e->get_name() << "!\n";	
			health -= (this->_attack*2);
			e->set_hp(health);
		}else{
			cout << "You dealt " << _attack << "damage to " << e->get_name() << "!\n";
			health -= (this->_attack);
			e->set_hp(health);
		}
	}
	void AddItems(item* i){
		inventory.push_back(i);
	}
	void UseItems(item* i){
		if(i->get_itemID() >=5 && i->get_itemID() <=7){
			i->increaseStats(this);
			i->set_isEquipped = true;
			cout << i->get_name() << " has been equipped" << endl;
		}else if(i->get_itemID() <= 10 && i->get_itemID() >= 8){
			i->increaseStats(this);
			for(int k = 0; k < inventory.size(); k++){
                        	if(i == inventory.at(k)){
                                	inventory.erase(inventory.begin()+k);
                        	}
                	}		
		
		}
	}
	void equipWeapon(item* i){
		currentWeapon = i;
		_attack += i->get_attack();
	}
	void unequipWeapon(item* i){
		_attack -= i->get_attack();
		currentWeapon = nullptr;
	}
	int get_attack() {return _attack;}
	void set_attack(int a) {_attack = a;}
	int get_health() {return health;}
	void set_health(int h) {health = h;}
	int get_maxHealth() {return maxHealth;}
	void set_maxHealth(int m) {maxHealth = m;}
	int get_defense() {return defense;}
	void set_defense(int d) {defense = d;}
	int get_speed() {return speed;}
	void set_speed(int s) {speed = s;}
};

#endif //__PLAYER_HPP__
