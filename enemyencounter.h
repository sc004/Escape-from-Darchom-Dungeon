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

using namespace std;
class EnemyEncounter : public Encounter{
	private:
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
				cout << "Your HP:  " << to_string(p->get_hp()) << "\t"<< mob->get_name()<<"'s HP:  "<< to_string(mob->get_hp())<<endl;
				cout << "How would you like to proceed?\n" << "1 to attack, 2 to examine backpack."<<endl;
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
					p->attack(mob);
					inMenue1 = false;
				}
				else if(intResponse ==2){
					inMenue2=true;
					while(inMenu2){
						p->display_Inventory();
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
											p->unequipWeapon(p->currentW);
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
		}
		void enemyTurn(Player* p){
			int prev_hp= p->get_hp();
			mob->enemyAttk(p);
			int hplost = prev_hp - p->get_hp();
			cout << mob->get_name()<<"'s attack dealt "<< to_string(hplost) <<" damage to you."<<endl;
		}
	public:
		EnemyEncounter(int t): Encounter(t){
			 srand(time(0));
			 ItemGenerate* lootG = new ItemGenerate();
			 int mtype = rand() % 3 + 1;
			 int name = rand() % gName.length();
			 int itemType = rand() % 10 +1;
			 
			 if(mtype ==1){
				 
				 mob = new Goblin(50, 10, 10, 50,1, gName[name], new Knife(), lootG->makeItem(itemType));
			 }
			 else if(mtype ==2){
				 
				 mob = new Troll(50, 10, 10, 50,2, tName[name], new Club(), lootG->makeItem(itemType));
			 }
			 else if(mtype ==3){
				 
				 mob = new Wizard(50, 10, 10, 50,3, wName[name], lootG->makeItem(itemType));
			 }
			 
			 
			 
			 
			 delete lootG;
		}
		~EnemyEncounter();
		void run(Player* p){
			bool isOver = false;
			cout << "You have encountered " << mob->get_name() <<".  It engages you in a fight.\n";
			/*calculate who is faster to determine the turn order*/
			if(mob->get_speed() > p->get_speed()){/*enemy stars first*/
				cout << mob->get_name() << " is faster than you, so it strikes first!"<<endl;
				while(!isOver){
					enemyTurn();
					if(p->get_hp()<=0){
						isOver=true;
						continue;
					}
					playerTurn(p);
					if(mob->get_hp()<=0){
						isOver=true
						continue;
					}	
				}
			}
			else{/*otherwise player goes first*/
				cout << "You are faster than the enemy, so you go first!"<<endl;
				while(!isOver){
					playerTurn(p);
					if(mob->get_hp()<=0){
						isOver=true
						continue;
					}
					enemyTurn();
					if(p->get_hp()<=0){
						isOver=true;
						continue;
					}
				}
			}
		}
		
		
};
#endif //ENEMYENCOUNTER_H
