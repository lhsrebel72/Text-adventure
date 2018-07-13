#pragma once
#include <string>
#include "Backpack.h"
#include "Item.h"
//The player class holds all the information for the player character in the story

//to-do:make stats more important 
using namespace std;

class Character
{
private:
	string charName; 
	enum statNames {Strength, Perception, Endurance, Charisma, Intelligence, Agility, Luck};//Player's stats effect many different things such as HP, Attack, and Defense
	int stats[8]; //array to hold the stats
	int level;//attack, HP, and Defense are all scaled according to level NOT YET IMPLEMENTED
	int maxHP, HP;//maxHP is determined by Endurance and Strength stats and level it is the maximum amount of HP the player can have, HP is the current health the player has.
	//include things such as speed which is based on agility, armor type, and stamina. base stamina depends on endurance, will be drained by weight of armor and weapon and actions.
	//same thing for power which is based on strength instead
	int baseAttack, attackBonus, totalAttack;//base attack is determined by strength, agility, and level. attackBonus is determined by items the player has equipped. totalAttack is baseAttack + bonusAttack and is the value used in combat
	int baseDefense, defenseBonus, totalDefense;//same as attack variables but baseDefense is based on strength and endurance
	Backpack playerInventory;//this is the player's inventory and is used to store and equip items. Equipped items can affect HP, maxHP, bonusAttack, and bonusDefense.
	

public:
	Character();
	~Character();

	void characterCreation (int * playerStats , string playerName);//function used to take values from the main program when first creating character
	void lvlUp();//function used to increase stats,baseAttack,baseDefense, and maxHP when the player levels up

	//these are self-explanatory and used in the main function for different situations
	string getName() { return charName; }
	int getHp() { return HP; }
	int getAttack() { return totalAttack; };
	int getLevel() { return level; }
	int getDefense() { return totalDefense; }
	void takeDamage(int damageTaken) { HP = HP - damageTaken; };

	//all of these refer to the backpack class to handle playerInventory
	void addInv(Item newItem) { playerInventory.insert(newItem); };
	void showInv();
	void showEquipped() { playerInventory.showEquipped(); }; //BROKEN
};

