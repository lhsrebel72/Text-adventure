#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "Item.h"
#include "Backpack.h"
//clean up duties(finish as you work)/add in stats and there effects
using namespace std;


class Mob
{
private:
	string name;
	enum statNames { Strength, Perception, Endurance, Charisma, Intelligence, Agility, Luck };//Player's stats effect many different things such as HP, Attack, and Defense
	int stats[8]; //array to hold the stats
	int level;//attack, HP, and Defense are all scaled according to level
	int maxHP, HP;//maxHP is determined by Endurance and Strength stats and level it is the maximum amount of HP the player can have, HP is the current health the player has.
	int baseAttack, attackBonus, totalAttack;//base attack is determined by strength, agility, and level. attackBonus is determined by items the player has equipped. totalAttack is baseAttack + bonusAttack and is the value used in combat
	int baseDefense, defenseBonus, totalDefense;//same as attack variables but baseDefense is based on strength and endurance
	Backpack mobInventory;//this is the player's inventory and is used to store and equip items. Equipped items can affect HP, maxHP, bonusAttack, and bonusDefense.

public:
	Mob(int * mobStats, string mobName);
	~Mob();
	int getHealth() { return HP; };
	int getAttack() { return totalAttack; };
	int getDefense() { return totalDefense; };
	void takeDamage(int dmg) { HP = HP - dmg; };
	void defendOutcome(int atkChoice, int attack, int def);
	int attackOutcome(int defChoice, int def);

	//all of these refer to the backpack class to handle mobInventory
	void addInv(Item newItem) { mobInventory.insert(newItem); mobEquip(); };
	void mobEquip() { mobInventory.mobInv(); 
	attackBonus = mobInventory.getAttBon();
	defenseBonus = mobInventory.getDefBon();
	totalAttack = attackBonus + baseAttack;
	totalDefense = defenseBonus + baseDefense;
	};
	void showEquipped() { mobInventory.showEquipped(); }; //BROKEN
	void showInv() { mobInventory.showInv(); }
};

