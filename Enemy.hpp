#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include <iostream>
#include "player.h"
#include <cstdlib>
#include <ctime>

class Enemy {
    private:
        int hp;
        int attack;
        int defense;
        int speed;
        int weakness;
        std::string name;
    public :
        Enemy(int _hp, int _attack, int _defense, int _speed, int _weakness, std::string _name) {
            hp = _hp; 
            attack = _attack;
            defense = _defense;
            speed = _speed;
            weakness = _weakness;
            name = _name;
        }
	~Enemy();
        virtual void enemyAttk(Player* p1) = 0;
        int get_hp() {return hp;}
	void set_hp(int healt) {hp = healt;}
        int get_attack() {return attack;}
        int get_defense() {return defense;}
        int get_speed() {return speed;}
        int get_weakness() {return weakness;}
        std::string get_name() { return name;}
};

#endif // __ENEMY_HPP__
