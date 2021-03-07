#ifndef __DUNGEON_H__
#define __DUNGEON_H__
#include <iostream>
#include <string>


#include "player.h"
#include "levelA.h"
#include "levelB.h"
#include "levelC.h"


using namespace std;

	class dungeon : public dungeonManager {
		public:
		Dungeon(int L){
			currentLevel = L;
			buildLevels();
		}
		void buildLevels(){
			for (int i=0;i<getLevels();i++){//does this for each level
				int type = rand() % 30 + 1;
				if(type <=10){
					this->levels.pushback(new LevelA());
				}
				else if(type > 10 && type <=20){
					this->levels.pushback(new LevelB());
				}
				else{
					this->levels.pushback(new LevelC());
				}
			}
		}
		void generatePlayer(){
			int attack;
			int health;
			int speed;
			int defense;
			bool validHealth = false;
			bool validAttack = false;
			bool validDefense = false;
			bool validSpeed = false;
			bool isDone = false;
			cout << "Please enter the player's stats in the order: health, attack, defense, speed" << endl;
			while(!isDone){
				cout << "Enter player health: (1 to 200) " << endl;
				try{cin << health;
				}
				catch{
					cout << "Please input a valid argument!" << endl;
					continue;
				}
				if(health < 0 || health > 200){
					cout << "Invalid health stat entered. Try again" << endl;
					while(!validHealth){
						cout << "Enter player health: " << endl;
						try{cin << health;
						}
						catch{
							cout << "Please input a valid argument1" << endl;
							continue;
						}
						if(health <= 0 || health > 200){
							cout << "Invalid health stat entered. Try again" << endl;
						}else{
							validHealth = true;
						}
					}
				}
				cout << "Enter player attack: (0 to 200)" << endl;
				try{cin << attack;
				}
				catch{
					cout << Please input a valid argument!" << endl;
				}
				if(attack < 0 || attack > 200){
					cout << "Invalid attack stat entered. Try again" << endl;
					while(!validAttack){
						cout << "Enter player attack: " << endl;
						try{cin << attack;
						}
						catch{
						cout << "Please input a valid argument!" << endl;
						continue;
						}
						if(attack < 0 || attack > 200){
							cout << "Invalid attack stat entered. Try again" << endl;
						}else{
							validAttack = true;
						}
					}	
				}
				cout << "Enter player defense: " << endl;
				try{cin << defense;
				}
				catch{
					cout << "Please input a valid argument1" << endl;
					continue;
				}
				if(defense < 0 || defense > 200){
					cout << "Invalid defense stat entered. Try again" << endl;
					while(!invalidDefense){
						cout << "Enter defense stat: " << endl;
						try{cin << defense;
						}
						catch{
						cout << "Please input a valid argument!" << endl;
						continue;
						}
						if(defense < 0 || defense > 200){
							cout << "Invalid defense stat entered. Try again" << endl;
						}else{
							validDefense = true;
						}
					}
				}
				cout << "Enter player speed: " << endl;
				try{cin << speed;
				}
				catch{
					cout << "Please input a valid argument!" << endl;
					continue;
				}
				if(speed < 0 || defense > 200){
					cout << "Invalid defense stat entered. Try again" << endl;
					while(!invalidSpeed){
						cout << "Enter speed stat: " << endl;
						try{cin << speed;
						}
						catch{
							cout << "Please input a valid argument!" << endl;
							continue;
						}
						if(speed < 0 || speed > 200){
							cout << "Invalid speed stat entered. Try again" << endl;
						}else{
							validSpeed = true;	
						}
					}
				}
			
				user  = new Player(health,attack,defense,speed);
			}	
		}
		private:
			int currentLevel;
			Player* user;


#endif

