#include "stdafx.h"
#include "Item.h"


Item::Item()//creates nullItem
{
	id = 0;
	weight = 0;
	price = 0;
	description = "None";
	bonus = 0;
	name = "Empty";
}

Item::Item(int ID) //creates an item with no stats
{
	id = ID;
	weight = 0;
	price = 0;
	description = "None";
	bonus = 0;
	name = "None";
}
Item::Item(int ID, int w,int a,int p,string n) //creates full item
{
	id = ID;
	weight = w;
	price = p;
	description = "NONE";
	bonus = a;
	name = n;
}



Item::~Item()
{
}
