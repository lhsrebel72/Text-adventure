#include "stdafx.h"
#include "Mob.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

Mob::Mob(int * mobStats, string mobName)
{
	name = mobName;
	level = 1;
	for (int i = 0; i < 7; i++) {
		stats[i] = mobStats[i];
	}
	baseAttack = (stats[Strength] + stats[Agility] / 2);//strength is the main determining factor of attack while agility is second thus it is halved
	baseDefense = (stats[Strength] + stats[Endurance] / 2);//endurance is the main determining factor of attack while strength is second thus it is halved
	maxHP = ((stats[Endurance] + stats[Strength] / 2) * 14);//endurance is the main determining factor of attack while strength is second thus it is halved
	HP = maxHP;
	attackBonus = 0;//nothing is equipped upon chacter creation thus bonus = 0
	totalAttack = baseAttack;
	totalDefense = baseDefense;
}


Mob::~Mob()
{
}

void Mob::defendOutcome(int atkChoice, int atk, int def)//for this and attack make mob more likely to choose an action based on its own stats and weapon/armor-player character can detect what they might do based on perception.
//also make hit chance and modifiers dependent on pc and npc stats and equipment
{
	srand(time(0));
	int realDamage = 0;
	int damage = 0;
	int blockPenalty = 0;
	int hitChance = 0;
	double modifier = 0;
	int defChoice = rand()%3+1;
	cout << "THIS IS THE DEFENCE CHOICE ->" << defChoice<<endl;
	if (atkChoice == 1) {
		hitChance = 80;
			if (defChoice == 1) {
				modifier = 2;
				hitChance += 10;
				cout << name << " attempted to dodge your attack(q)\n";
			}
			else if (defChoice == 2) {
				modifier = 1;
				hitChance -= 50;
				cout << name << " attempted to parry your attack(q)\n";
			}
			else if (defChoice == 3) {
				modifier = 2.5;
				hitChance -= 45;
				blockPenalty = 10;
				cout << name << " attempted to block your attack(q)\n";
			}
	}
	else if (atkChoice == 2) {
		hitChance = 50;
		if (defChoice == 1) {
			modifier = 2.5;
			hitChance -= 30;
			cout << name << " attempted to dodge your attack(s)\n";
		}
		else if (defChoice == 2) {
			modifier = 4;
			hitChance += 40;
			cout << name << " attempted to parry your attack(s)\n";
		}
		else if (defChoice == 3) {
			modifier = 3;
			hitChance -= 45;
			blockPenalty = 20;
			cout << name << " attempted to block your attack(s)\n";
		}
	}
	else if (atkChoice == 3) {
		hitChance = 70;
		if (defChoice == 1) {
			modifier = 1;
			hitChance -= 10;
			cout << name << " attempted to dodge your attack(b)\n";
		}
		else if (defChoice == 2) {
			modifier = 1;
			hitChance -= 5;
			cout << name << " attempted to parry your attack(b)\n";
		}
		else if (defChoice == 3) {
			modifier = .5;
			hitChance -= 45;
			blockPenalty = atk/2;
			cout << name << " attempted to block your attack(b)\n";
		}
	}
	damage = atk * modifier + blockPenalty;
	int chanceVar = rand() % 100 + 1;
	cout << "ChanceVar: " << chanceVar << endl << "hitChance:" << hitChance << endl;
	if (chanceVar <= hitChance) {
		cout << "HP: " << HP << endl ;
		realDamage = damage - totalDefense;
		if (realDamage > 0) HP = HP - realDamage;
		cout << "success! You landed your attack for " << realDamage << " damage!\n";
	}
	else {
		realDamage = blockPenalty - totalDefense;
		if (realDamage > 0) HP = HP - realDamage;
		cout << "Your attack failed you only caused " << blockPenalty << " damage\n";
	}
}

int Mob::attackOutcome(int defChoice, int def)
{
	srand(time(0));
	int realDamage = 0;
	int damage = 0;
	int blockPenalty = 0;
	int hitChance = 50;
	double modifier = 1;
	int atkChoice = rand() % 3 + 1;
	cout << "THIS IS THE attack CHOICE ->" << atkChoice << endl;
	if (atkChoice == 1) {
		hitChance = 80;
		if (defChoice == 1) {
			modifier = 2;
			hitChance += 10;
			cout << name << " attempted quick attack(d)\n";
		}
		else if (defChoice == 2) {
			modifier = 1.5;
			hitChance -= 50;
			cout << name << " attempted quick attack(p)\n";
		}
		else if (defChoice == 3) {
			modifier = 1;
			hitChance -= 45;
			blockPenalty = 10;
			cout << name << " attempted quick attack(b)\n";
		}
	}
	else if (atkChoice == 2) {
		hitChance = 50;
		if (defChoice == 1) {
			modifier = 2.5;
			hitChance -= 30;
			cout << name << " attempted strong attack(d)\n";
		}
		else if (defChoice == 2) {
			modifier = 4;
			hitChance += 40;
			cout << name << " attempted strong attack(p)\n";
		}
		else if (defChoice == 3) {
			modifier = 1;
			hitChance -= 45;
			blockPenalty = 20;
			cout << name << " attempted strong attack(b)\n";
		}
	}
	else if (atkChoice == 3) {
		hitChance = 70;
		if (defChoice == 1) {
			modifier = 1;
			hitChance -= 10;
			cout << name << " attempted basic attack(d)\n";
		}
		else if (defChoice == 2) {
			modifier = 1;
			hitChance -= 5;
			cout << name << " attempted basic attack(p)\n";
		}
		else if (defChoice == 3) {
			modifier = .5;
			hitChance -= 45;
			blockPenalty = totalAttack/2;
			cout << name << " attempted basic attack(b)\n";
		}
	}
	damage = totalAttack * modifier + blockPenalty;
	int chanceVar = rand() % 100 + 1;
	cout << "THIS IS THE CHANCE VAR->" << chanceVar << endl;
	if (chanceVar <= hitChance) {
		realDamage = damage - totalDefense;
		cout << "failure! "<<name<<" landed attack for " << realDamage << " damage!\n";
		if (realDamage > 0) return realDamage;
		else return 0;
	}
	else {
		realDamage = blockPenalty - totalDefense;
		cout << "Succesful defense! "<< name <<" only caused " << realDamage << " damage\n";
		if (realDamage > 0) return realDamage;
		else return 0;
	}
}


