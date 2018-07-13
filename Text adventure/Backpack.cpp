#include "stdafx.h"
#include "Backpack.h"
#include <iostream>

using namespace std;


Backpack::Backpack()//constructor
{	//creates an empty backpack filled with nullItem
	Item nullItem; 
	equipped[0] = nullItem;
	equipped[1] = nullItem;
	attBon = 0;
	for (int i = 0; i <= 25; i++) 
	{
		weapons[i] = nullItem;
		armor[i] = nullItem;
		consumables[i] = nullItem;
	}
	GP = 200;//starting gold for a new player
}


Backpack::~Backpack()
{
}

void Backpack::insert(Item newItem)//inserts an item into the next empty slot of the backpack
{
	int i = 0; //starts the search at the beggining of the list
	if (newItem.getid() < 2000 && newItem.getid() > 999) {
		Item nullItem;
		while (i <= 25) {
			if (weapons[i].getid() == 0) {//determines if the slot is empty --  if so, then an item is placed there and the search is terminated
				weapons[i] = newItem;
				weapons[i + 1] = nullItem;
				i = 25;
			}
			i++;//moves to the next slot if the slot wasn't empty
		}
	}
	if (newItem.getid() < 3000 && newItem.getid() > 1999) {
		Item nullItem;
		while (i <= 25) {
			if (armor[i].getid() == 0) {//determines if the slot is empty --  if so, then an item is placed there and the search is terminated
				armor[i] = newItem;
				armor[i + 1] = nullItem;
				i = 25;
			}
			i++;//moves to the next slot if the slot wasn't empty
		}
	}
}

void Backpack::showInv() //displays the inventory
{
	int choice;
	int exit = 1;
	do {
		int i = 0;
		cout << "Gold: " << GP << endl;
		cout << "equipped armor: " << equipped[0] << endl;
		cout << "equipped weapon: " << equipped[1] << endl;
		cout << "0. Exit\n1. Weapons\n2. Armor\n";
		cin >> choice;
		if (choice == 0) exit = 0;
		if (choice == 1) {
			do {
				cout << "____Weapons____" << endl;
				while (weapons[i].getid() != 0)
				{
					cout << i + 1 << ": " << weapons[i] << endl;
					i++;
				}
				cout << "To equip a weapon please press 1. To exit enter 0";
				cin >> choice;
				if (choice == 1)
				{
					cout << "Please enter the corrosponding number of the weapon you want to equip";
					cin >> choice;
					equip(weapons[choice - 1]);
				}
			} while (choice != 0);
		}
		if (choice == 2) {
			do {
				cout << "____Armor____" << endl;
				while (armor[i].getid() != 0)
				{
					cout << i + 1 << ": " << armor[i] << endl;
					i++;
				}
				cout << "To equip armor please press 1. To exit enter 0";
				cin >> choice;
				if (choice == 1)
				{
					cout << "Please enter the corrosponding number of the armor you want to equip";
					cin >> choice;
					equip(armor[choice - 1]);
				}
			} while (choice != 0);
		}
	} while (exit != 0);
}

void Backpack::equip(Item itemToEquip) 
{
	if (itemToEquip.getid() < 2000 && itemToEquip.getid() > 999) {
		equipped[1] = itemToEquip;
		attBon = itemToEquip.getAttBonItem();
		cout <<endl<< equipped[1] <<endl;
	}
	if (itemToEquip.getid() < 3000 && itemToEquip.getid() > 1999) {
		equipped[0] = itemToEquip;
		defBon = itemToEquip.getAttBonItem();
		cout << endl << equipped[0] << endl;
	}

}

void::Backpack::mobInv() { 
	Item itemToEquip = weapons[0]; //starts searching at the first item in the list
	int current = weapons[0].getAttBonItem(); //used to compare strength of the current weapon
	int compare; //checks if the strength of the next weapon is stronger than current
	int nullCheck = 1; //if the next weapon slot is empty it stops searching
	for (int i = 1; i <= 25; i++) { // run through the list to find the strongest weapon
		if (weapons[i].getid() == 0) nullCheck = 0;
		compare = weapons[i].getAttBonItem();
		if (current < compare && nullCheck != 0) { itemToEquip = weapons[i]; current = itemToEquip.getAttBonItem(); }
		if (weapons[i].getid() == 0) { i = 25; }
	}
	equip(itemToEquip);
	//do the same for armor
	itemToEquip = armor[0]; //starts searching at the first item in the list
	current = armor[0].getAttBonItem(); //used to compare strength of the current weapon
	compare; //checks if the strength of the next weapon is stronger than current
	nullCheck = 1; //if the next weapon slot is empty it stops searching
	for (int i = 1; i <= 25; i++) { // run through the list to find the strongest weapon
		if (armor[i].getid() == 0) nullCheck = 0;
		compare = armor[i].getAttBonItem();
		if (current < compare && nullCheck != 0) { itemToEquip = armor[i]; current = itemToEquip.getAttBonItem(); }
		if (armor[i].getid() == 0) { i = 25; }
	}
	equip(itemToEquip);
}