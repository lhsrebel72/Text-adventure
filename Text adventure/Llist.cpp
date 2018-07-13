#include "stdafx.h"
#include "Llist.h"
#include<iostream>

Llist::~Llist()
{
	Node * temp;
	while (first != 0) {
		temp = first->next;
		delete first;
		first = temp;
	}
}
