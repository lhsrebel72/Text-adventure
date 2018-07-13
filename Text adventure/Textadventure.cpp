// Textadventure.cpp : Defines the entry point for the console application.
//
//to-do: 2. create mobs and items/3. create story and choices system/1. C. Improve combat(loot system and stats should play a role defense??),B. MOSTLY DONE -> mobs(need stats and inv defense??), and A. character (decide how stats effect things&balancing defense??) by integrating stats system into everything D. after integrating make touches to balance xxx ____FUTURE____create small test story/ continue adding features and full game
//ALSO ADD CLEAR SCREEN ABILITY AND INTEGRATE IT! IDEA-armor covers body parts and depending on type of attack certain chance to hit a body part, damage depends on type of armor and weapon - chance to cripple/disarm/ internal bleeding/ etc...
// MOB - needs work CHAR- needs work BACK - finished ITEM - done
#include "stdafx.h"
#include <string>
#include <iostream>
#include "Character.h"
#include "Llist.h"
#include "Item.h"
#include "Mob.h"
#include <cstdlib>
//THIS SHOULD BE COMBAT
using namespace std;

void generateList(Llist& tempList);
Character attackScene(Character main, Mob Goblin);


int main()
{
	int a;
	Character main;	
	string name;
	int stats[8];
	int * statPtr = stats;
	cout << "Enter Name:";
	cin >> name;
	for (int i = 0; i < 7; i++) {
		stats[i]=5;
	}
	main.characterCreation(statPtr, name);
	cout << main.getName()<<endl<<"HP:"<<main.getHp()<<endl<<"att"<<main.getAttack()<<endl;
	cin >> a;
	Llist itemList;
	generateList(itemList);
	main.addInv(itemList.find(1001));
	main.addInv(itemList.find(1000));
	main.addInv(itemList.find(2001));
	main.addInv(itemList.find(2000));
	main.showInv();
	Mob Goblin(statPtr, "Goblin");
	Goblin.addInv(itemList.find(1001));
	Goblin.addInv(itemList.find(1000));
	Goblin.addInv(itemList.find(2001));
	Goblin.addInv(itemList.find(2000));
	cin >> a;
	main = attackScene(main,Goblin);
	cout << main.getHp();
	cin >> a;
	

}

void generateList(Llist & itemList) { //as each item is created it is stored in a Llist, each node of the Llist holds an item and is represented and found by that items ID#
	//to add an item first create the item and its values (ID, weight, attack bonus, price, name) then, insert each item into list (ID, item)
	//to access an item after it is placed into a list use find function .find(id #)
	Item a(1000,15,10,50,"Iron Sword");
	Item b(1001,10,5,20,"Wooden Club");
	Item c(2000, 30, 20, 250, "Iron armor");
	Item d(2001, 5, 5, 50, "Leather armor");
	itemList.insert(1000,a); //1000 is the ID number and is stored as the value of the node, the item "a" is stored in that node also.
	itemList.insert(1001,b);
	itemList.insert(2000, c);
	itemList.insert(2001, d);
	return;
}

Character attackScene(Character main, Mob Goblin) 
{
	cout << main.getName() << endl << "HP:" << main.getHp() << endl << "att" << main.getAttack() << endl;
	int choice;
	cout << "You are attacked by a goblin!!!";
	
	cout <<"Goblin-"<< Goblin.getHealth()<<"hp"<<endl;
	do {
		cout << "choose an action" << endl << "1. Quick Attack" << endl << "2. Strong Attack" << endl << "3. Basic Attack";
		cin >> choice;
		Goblin.defendOutcome(choice, main.getAttack(), main.getDefense());
		if (Goblin.getHealth() > 0) {
			cout << Goblin.getHealth();
			cout << "choose an action" << endl << "1. Dodge" << endl << "2. Parry" << endl << "3. Block";
			cin >> choice;
			main.takeDamage(Goblin.attackOutcome(choice,main.getDefense()));
			cout << "Goblin-" << Goblin.getHealth() << "hp" << endl;
			cout << main.getName() << endl << "HP:" << main.getHp() << endl << "att" << main.getAttack() << endl;
		}
	} while (Goblin.getHealth() > 0 && main.getHp() > 0);
	if (Goblin.getHealth() > main.getHp()) cout << "you died!!!";
	else cout << "You won!!";
	cout << main.getHp();
	cin >> choice;
	return main;
}

//void mobList() {
	//same as items but for enemy NPCs
//}
