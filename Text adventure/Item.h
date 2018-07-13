#pragma once
#include <string>
#include <iostream>

using namespace std;

class Item
{
private: //values each item can hold.
	int bonus; //amount of bonus an item provides (attack for weapong, defense for armor)
	int id; //used to find and store each individual item (number determines item type)
	int price; //how much gold item costs
	int weight; //how much weight item takes up in inventory
	string description; 
	string name;

public:
	Item();
	Item(int ID);
	Item(int ID, int w, int a, int p, string n);
	~Item();

	//returns info about a specific item
	string getName() { return name; };
	int getPrice() { return price; };
	int getAttBonItem() { return bonus; };
	int getid() { return id; };

	//changes item values
	void setName(string a) { name = a; };
	void setPrice(int a) { price = a; };
	void setAttBon(int a) { bonus = a; };
	void setid(int a) { id = a; };

	//displays item details to console
	void display(ostream & out) {
		cout << name<<endl;
		cout <<"Price: "<< price<<endl;
		if (id < 2000 && id > 999) cout << "Damage: " << bonus << endl;
		if (id < 3000 && id > 1999) cout << "Defense: " << bonus << endl;
	}

	friend ostream & operator<<(ostream &out, Item & I);
};

inline ostream & operator<<(ostream &out, Item & I) { I.display(out); return out; }


