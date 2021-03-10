#ifndef ENEMYENCOUNTER_H
#define ENEMYENCOUNTER_H

#include <iostream>
#include <string>
#include "itemgenerate.h"
#include "Enemy.hpp"
#include "Goblin.hpp"
#include "Troll.hpp"
#include "Wizard.hpp"
#include "Player.hpp"
#include "knife.h"
#include "club.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;
class EnemyEncounter : public Encounter{
	private:
		Knife* k1= nullptr;
		Club* c1= nullptr;
		item* i1= nullptr;
		int type;
		Enemy* mob;
		string gName[10] = {"Wizz","Coibs","Trik","Grelk","Ild","Kreelkerd","Glelsaalb","Diazozz","Toinalx","Kigeazz"};
		string tName[10] = {"Dorkuraz","Erodjan","Lakjin","Vulzal","Quivilt","Ayagi","Jaafan","Wonjin","Ttarmek","Rashi"};
		string wName[10] = {"Amarim","Zomazz","Crekius","Axon","Adrufaris","Jabahn","Ilridalf","Drumorn","Uxius","Exium"};
		void playerTurn(Player* p){
			bool inMenue1 = true;
			bool inMenue2 = false;
			bool inMenue3 = false;
			string response;
			int intResponse1;
			int intResponse2;
			while(inMenue1){
				cout << "Your HP:  " << to_string(p->get_health()) << "\t"<< mob->get_name()<<"'s HP:  "<< to_string(mob->get_hp())<<endl;
				cout << "How would you like to proceed?\n" << "1 to attack, 2 to examine backpack."<<endl;
				cin >> response;
				try{
					intResponse1 = stoi(response);
				}
				catch(int e){
					cout << "Please input a valid argument!"<<endl;
					continue;
				}
				if(intResponse1 != 1 && intResponse1 != 2){
					cout << "Please select one of the two responses!"<<endl;
					continue;
				}
				/*now we have a valid response*/
				if(intResponse1 == 1){	
					p->attack(mob);
					if(p->get_status() == 1){
						cout << "You took 3 damage from Poison! You have " << p->get_Counter() << " turns of Poison remaining" << endl;
						p->set_Counter(p->get_Counter() - 1);
						p->set_health(p->get_health() - 3);
						
					}
					if(p->get_status() == 2){
						cout << "You took 3 damage from Bleed! You have " << p->get_Counter() << " turns of Bleed remaining" << endl;
						p->set_Counter(p->get_Counter() - 1);
						p->set_health(p->get_health() - 3);
					}
					if(p->get_status() == 3){
						cout << "You are crippled! Your speed will get reduced by 5 for " << p->get_Counter() << " turns" << endl;
						p->set_Counter(p->get_Counter() - 1);
						p->set_speed(p->get_speed() - 5);
						
					}
					if(p->get_Counter() == 0 && p->get_status() != 0){
						cout << "You are no longer afflicted with the previous ailment." << endl;
						p->set_status(0);
					}
					inMenue1 = false;
				}
				else if(intResponse1 ==2){
					inMenue2=true;
					while(inMenue2){
						p->displayInventory();
						cout << "Which item would you like to interact with?\n" << "Respond with its number or 0 to back out."<<endl;
						cin >> response;
						try{
							intResponse2 = stoi(response);
						}
						catch(int e){
							cout << "Please input a valid argument!"<<endl;
							continue;
						}
						if(intResponse2 <0 || intResponse2 > p->inventory.size()){
							cout << "Please give a valid item number or 0!"<<endl;
							continue;
						}
						if(intResponse2 ==0){
							inMenue2 = false;
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
											p->set_blocking(true);
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
										cout << p->inventory.at(intResponse2-1)->get_name() <<" is not currently equipped.\nThere is nothing else you can do with this at this time."<<endl;
									}
									inMenue3=false;
									continue;
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
										p->UseItems(p->inventory.at(intResponse2-1));
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
		}
		void enemyTurn(Player* p){
			if(p->get_blocking()){
				cout << "You successfully blocked " << mob->get_name()<<"'s attack!"<<endl;
				p->set_blocking(false); 
			}
			else{
				int prev_hp= p->get_health();
				p->set_health(mob->enemyAttk(prev_hp, p->get_defense()));
				int hplost = prev_hp - p->get_health();
				cout << mob->get_name()<<"'s attack dealt "<< to_string(hplost) <<" damage to you."<<endl;
			}
		}
	public:
		EnemyEncounter(int t): Encounter(t){
			 ItemGenerate* lootG = new ItemGenerate();
			 int mtype = (rand() % 3) + 1;
			 int name = rand() % 10;
			 int itemType = (rand() % 10) + 1;
			 i1 = lootG->makeItem(itemType);
			 if(mtype ==1){
				k1 = new Knife();
				mob = new Goblin(50, 10, 10, 50,1, "Goblin "+gName[name], k1, i1);
			 }
			 else if(mtype ==2){
				c1 = new Club(); 
				mob = new Troll(100, 10, 10, 50,2, "Troll "+tName[name], c1, i1);
			 }
			 else if(mtype ==3){
				 
				mob = new Wizard(90, 10, 10, 50,3, "Wizard "+wName[name], i1);
			 }
			delete lootG;
		}
		~EnemyEncounter(){
			delete mob;
			if(i1!= nullptr && i1!=NULL){
				delete i1;
			}
			if(c1!= nullptr && c1!=NULL){
                                delete c1;
                        }
			if(k1!= nullptr && k1!=NULL){
                                delete k1;
                        }
		}
		void run(Player* p){
			bool isOver = false;
			cout << "You have encountered " << mob->get_name() <<".  It engages you in a fight.\n";
			/*calculate who is faster to determine the turn order*/
			if(mob->get_speed() > p->get_speed()){/*enemy stars first*/
				cout << mob->get_name() << " is faster than you, so it strikes first!"<<endl;
				while(!isOver){
					enemyTurn(p);
					if(p->get_health()<=0){
						isOver=true;
						continue;
					}
					playerTurn(p);
					if(mob->get_hp()<=0){
						isOver=true;
						p->AddItems(mob->get_loot());
						i1=nullptr;
						continue;
					}	
				}
			}
			else{/*otherwise player goes first*/
				cout << "You are faster than the enemy, so you go first!"<<endl;
				while(!isOver){
					playerTurn(p);
					if(mob->get_hp()<=0){
						p->AddItems(mob->get_loot());
						i1=nullptr;
						isOver=true;
						continue;
					}
					enemyTurn(p);
					if(p->get_health()<=0){
						isOver=true;
						continue;
					}
				}
			}
		}
		
		
};
#endif //ENEMYENCOUNTER_H
