#ifndef __DUNGEON_MANAGER_H__
#define __DUNGEON_MANAGER_H__

#include "level.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class dungeonManager{
	protected:
		int levelCount;
		vector<Level*> levels;
	public:
		dungeonManager(){
		bool isDone = false;
		string response;
			cout << "How many levels would you like to generate (Please enter a number from 1 to 10)" << endl;
			while(!isDone){
				cin >> response;
				int Response2;
				try{
				Response2 = stoi(response);
				}
				catch(int e){
				cout << "Please input a valid argument!" <<endl;
				continue;
				}
				if(Response2 < 0 || Response2 == 0){
					cout << "Invalid input: Number is negative or 0" << endl;
				}else if(Response2 > 10){
					cout << "Invalid input: Too large of a number" << endl;
				}		 
				else{
					levelCount = Response2;
					isDone = true;
				}
			}
		}
		int getLevels(){
			return levelCount;
		}
		void virtual buildLevels() = 0;
};

#endif
