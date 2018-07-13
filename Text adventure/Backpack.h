#pragma once
#include <string>
#include "item.h"
#include "Llist.h"
#include <iostream>

using namespace std;

class Backpack //used to store items for the player character and mobs, handle equipping the items, and looting from mobs
{
private:
	int GP;//amount of gold-main currency in game
	int attBon;//attack bonus from equipped items
	int defBon;//defense bonus from equipped items
	Item weapons[25];//array to hold a maximum of 25 weapon items
	Item armor[25];//array to hold a maximum of 25 armor items
	Item consumables[50];//array to hold a maximum of 50 consumable items
	Item equipped[2];//items equipped-only two slots right now slot 1 is for weapon slot 2 for armor
	void equip(Item itemToEquip);//function used to equip an item and apply its bonus(only accesible through showInv function)

public:
	Backpack();
	~Backpack();
	void insert(Item newItem);//inserts item into the corrosponding Item array
	void showInv();//shows inventory and gives the option to equip items
	void showEquipped() { cout << "Weapon Slot:" << equipped[1]; cout << "Armor Slot:" << equipped[2]; }//displays currently equipped items-BROKEN
	int getAttBon() { return attBon; };//returns attack bonus to update player stats after equipping an item
	int getDefBon() { return defBon; };//returns defens bonus to update player stats after equipping an item
	void mobInv();//automatically equips best gear for mob
};

