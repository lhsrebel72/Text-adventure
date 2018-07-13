#include "stdafx.h"
#include "Character.h"

Character::Character() {

}

Character::~Character() {

}


void Character::lvlUp() 
{

}

void Character::characterCreation(int *charStats, string name)
{
	charName = name;
	level = 1;
	for (int i = 0; i < 7; i++) {
		stats[i]=charStats[i];
	}
	baseAttack = (stats[Strength] + stats[Agility]/2);//strength is the main determining factor of attack while agility is second thus it is halved
	baseDefense = (stats[Strength] + stats[Endurance]/2);//endurance is the main determining factor of attack while strength is second thus it is halved
	maxHP = ((stats[Endurance] + stats[Strength]/2)*14);//endurance is the main determining factor of attack while strength is second thus it is halved
	HP = maxHP;
	attackBonus = 0;//nothing is equipped upon chacter creation thus bonus = 0
	totalAttack = baseAttack;
	totalDefense = baseDefense;
}


void Character::showInv()//runs the showInv function of the Backpack class-in this function the player has the opportunity to change which items are equipped so changes are made to attack/defenseBonus and totalAttack/Defense
{
	playerInventory.showInv();
	attackBonus = playerInventory.getAttBon();
	defenseBonus = playerInventory.getDefBon();
	totalAttack = attackBonus + baseAttack;
	totalDefense = defenseBonus + baseDefense;
}

