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
			for (int i=0;i<this->getLevels();i++){//does this for each level
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
			//int defense;
			bool validHealth = false;
			bool validAttack = false;
			//bool validDefense = false;
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
					cout << "Please input a valid argument!" << endl;
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
				/*cout << "Enter player defense: " << endl;
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
				}*/
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
			void explore(){
				bool gameover = false;
				while(!gameover){
					for(int i=0;i<this->getlevels();i++){
						for(int j=0;j<levels.at(i)->encounters.size();j++){
							levels.at(i)->encounters.at(j)->run(user);
							if(user->get_health()<=0){
								cout <<"You are dead....."<< endl;
								gameover = true;
							}
							//menue
							bool inMenue1 = true;
			bool inMenue2 = false;
			bool inMenue3 = false;
			string response;
			int intResponse1;
			int intResponse2;
			while(inMenue1){
				cout << "Your HP:  " << to_string(p->get_hp()) << "\t"<< mob->get_name()<<"'s HP:  "<< to_string(mob->get_hp())<<endl;
				cout << "How would you like to proceed?\n" << "1 to move on, 2 to examine backpack."<<endl;
				cin >> response;
				try{
					intResponse1 = stoi(response);
				}
				catch{
					cout << "Please input a valid argument!"<<endl;
					continue;
				}
				if(intResponse1 != 1 || intResponse1 != 2){
					cout << "Please select one of the two responses!"<<endl;
					continue;
				}
				/*now we have a valid response*/
				if(intResponse ==1){
					inMenue1 = false;
				}
				else if(intResponse ==2){
					inMenue2=true;
					while(inMenu2){
						p->displayInventory();
						cout << "Which item would you like to interact with?\n" << "Respond with its number or 0 to back out."<<endl;
						cin >> response;
						try{
							intResponse2 = stoi(response);
						}
						catch{
							cout << "Please input a valid argument!"<<endl;
							continue;
						}
						if(intResponse2 <0 || intResponse2 > p->inventory.size()){
							cout << "Please give a valid item number or 0!"<<endl;
							continue;
						}
						if(intResponse2 ==0){
							inMenu2 = false;
							continue;
						}
						else{/*three cases to deal with; a weapon type, a potion, and armor
							for armor, cant equip in fight, just show stats of it,
							for weapon, show its durability and ask if player wants to equip it, if so, unequip current weap, then send new object to equip func,
							for potion, ask if player wants to consume it? if so run its increase stats function then remove it from inventory 
							check item's ID, 1-4 = weapon, 5-7 = armor, 8-10 = potion */	
							inMenue3 = true;
							while(inMenue3){
								if(p->inventory.at(intResponse2-1)->get_itemID()>=1 && p->inventory.at(intResponse2-1)->get_itemID()<=4){/*weapon if*/
									string advantage = "No Bonus";
									if(p->inventory.at(intResponse2-1)->get_itemID()==1){advantage = "versus goblins";}
									else if(p->inventory.at(intResponse2-1)->get_itemID()==2){advantage = "versus trolls";}
									else if(p->inventory.at(intResponse2-1)->get_itemID()==4){advantage = "versus wizards";}
									cout<< "Name: " << p->inventory.at(intResponse2-1)->get_name()<<"\t Bonus: "<< advantage<<endl;
									cout<< "Durability: "<< to_string(p->inventory.at(intResponse2-1)->get_durability());
									cout<< "Would you like to wield this? y to equip, n to back out"<<endl;
									cin>> response;
									if(response != "y"&& response != "n"){
										cout <<"Please give a valid response!"<<endl;
										continue;
									}
									else if(response=="y"){
										if(p->inventory.at(intResponse2-1)->get_itemID()==3){
											p->blocking = true;
											cout<< "The " << p->inventory.at(intResponse2-1)->get_name()<< " is ready to recieve a blow."<<endl;
										}
										else{
											p->unequipWeapon(p->currentWeapon);
											p->equipWeapon(p->inventory.at(intResponse2-1));
											cout<< "You are now wielding your " <<p->inventory.at(intResponse2-1)->get_name() <<".\n";
										}
										/*player did equip, so back out of menu*/
										inMenue3=false;
										continue;
									}
									else{/*player did not want to equip, so back out of menu*/
										inMenue3=false;
										continue;
									}
								}
								else if(p->inventory.at(intResponse2-1)->get_itemID()>=5 && p->inventory.at(intResponse2-1)->get_itemID()<=7){/*armor if*/
									if(p->inventory.at(intResponse2-1)->get_isEquiped()){/*armor is equipped*/
										cout << p->inventory.at(intResponse2-1)->get_name() <<" is currently equipped.\nThere is nothing else you can do with this at this time."<<endl;
									}
									else{
										cout << p->inventory.at(intResponse2-1)->get_name() <<" is not currently equipped.\nWould you like to equip it now? y to equip, n to back out."<<endl;
										bool rCheck=false;
										while (!rCheck){
                                                                                	cin>> response;
                                                                                	if(response !="y" && response != "n"){
                                                                                        	cout <<"Please give a valid response!"<<endl;
                                                                                        	continue;
                                                                                	}
                                                                                	else{rCheck = true;}
                                                                        	}
                                                                        	if (response == "y"){
                                                                                	p->UseItem(p->inventory.at(intResponse2-1));
										}
										inMenue3=false;
									}
									inMenue3=false;
									continue
								}
								else{/*item is a potion*/
									bool rCheck = false;
									cout << p->inventory.at(intResponse2-1)->get_name()<<"\nWould you like to consume this? y to consume, n to back out"<<endl;
									while (!rCheck){
										cin>> response;
										if(response !="y" && response != "n"){
											cout <<"Please give a valid response!"<<endl;
											continue;
										}
										else{rCheck = true;}
									}
									if (response == "y"){
										p->UseItem(p->inventory.at(intResponse2-1));
									}
									/*if y wasnt selected, just back out*/
									inMenue3=false;
									continue;
								}
								
							}
						}
					}
				}
			}
							//end menue
							if(j+1<levels.at(i)->encounters.size()){
								cout << "You move onto the next room..."<< endl;
							}
						}
						if(i+1<this->getlevels()){
                                                                cout << "You have survived floor "<< to_string(i+1)<<" and move onto the next";
                               	                }
					}
					cout << "Congratulations, You have made it through all the floors of Darchom Dungeon!" << endl;
				}
				cout << "GAMEOVER!"<<endl;
			}	
		}
		private:
			int currentLevel;
			Player* user;


#endif
