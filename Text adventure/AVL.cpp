#include "stdafx.h"
#include "AVL.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void bstree::insert(int x, nodeptr &p)
{
	if (p == NULL)
	{
		p = new node;
		p->element = x;
		p->left = NULL;
		p->right = NULL;
		p->height = 0;
		if (p == NULL)
			cout << "Out of Space";
	}
	else
	{
		if (x<p->element)
		{
			insert(x, p->left);
			if ((bsheight(p->left) - bsheight(p->right)) == 2)
			{
				if (x < p->left->element)
					p = srl(p);
				else
					p = drl(p);
			}
		}
		else if (x>p->element)
		{
			insert(x, p->right);
			if ((bsheight(p->right) - bsheight(p->left)) == 2)
			{
				if (x > p->right->element)
					p = srr(p);
				else
					p = drr(p);
			}
		}
		else
			cout << "Element Exists";
	}
	int m, n, d;
	m = bsheight(p->left);
	n = bsheight(p->right);
	d = max(m, n);
	p->height = d + 1;

}

//		Finding the Smallest
nodeptr bstree::findmin(nodeptr p)
{
	if (p == NULL)
	{
			return p;
	}
	else
	{
		while (p->left != NULL)
			p = p->left;
		return p;
	}
}

//		Finding the Largest
nodeptr bstree::findmax(nodeptr p)
{
	if (p == NULL)
	{
		cout << "Empty Tree";
			return p;
	}
	else
	{
		while (p->right != NULL)
			p = p->right;
		return p;
	}
}

//		Finding an element
void bstree::find(int x, nodeptr &p)
{
	if (p == NULL) cout << "Element not found";
		
	else if (x < p->element) find(x, p->left);
		else if (x>p->element) find(x, p->right);
			else cout << "Element found !";
				

}

//		Copy a tree
void bstree::copy(nodeptr &p, nodeptr &p1)
{
	makeempty(p1);
	p1 = nodecopy(p);
}

//		Make a tree empty
void bstree::makeempty(nodeptr &p)
{
	nodeptr d;
	if (p != NULL)
	{
		makeempty(p->left);
		makeempty(p->right);
		d = p;
		free(d);
		p = NULL;
	}
}

//		Copy the nodes
nodeptr bstree::nodecopy(nodeptr &p)
{
	nodeptr temp;
	if (p == NULL)
		return p;
	else
	{
		temp = new node;
		temp->element = p->element;
		temp->left = nodecopy(p->left);
		temp->right = nodecopy(p->right);
		return temp;
	}
}

//		Deleting a node
void bstree::del(int x, nodeptr &p)
{
	nodeptr d;
	if (p == NULL)
		cout << "Element not found";
		
	else if (x < p->element) del(x, p->left);
	else if (x > p->element) del(x, p->right);
	else if ((p->left == NULL) && (p->right == NULL))
	{
		d = p;
		free(d);
		p = NULL;
		cout << "Element deleted";
	}
	else if (p->left == NULL)
	{
		d = p;
		free(d);
		p = p->right;
		cout << "Element deleted !";
	}
	else if (p->right == NULL)
	{
		d = p;
		p = p->left;
		free(d);
		cout << "Element deleted !";
	}
	else
		p->element = deletemin(p->right);
}

int bstree::deletemin(nodeptr &p)
{
	int c;
	cout << "inside deltemin";
		if (p->left == NULL)
		{
			c = p->element;
			p = p->right;
			return c;
		}
		else
		{
			c = deletemin(p->left);
			return c;
		}
}

void bstree::preorder(nodeptr p)
{
	if (p != NULL)
	{
		cout << p->element << "-->";
		preorder(p->left);
		preorder(p->right);
	}
}

//		Inorder Printing
void bstree::inorder(nodeptr p)
{
	if (p != NULL)
	{
		inorder(p->left);
		cout << p->element << "-->";
		inorder(p->right);
	}
}

//		PostOrder Printing
void bstree::postorder(nodeptr p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout << p->element << "-->";
	}
}

int bstree::max(int value1, int value2)
{
	return ((value1 > value2) ? value1 : value2);
}

int bstree::bsheight(nodeptr p)
{
	int t;
	if (p == NULL)
		return -1;
	else
	{
		t = p->height;
		return t;
	}
}

nodeptr bstree::srl(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = max(bsheight(p2->left), p1->height) + 1;
	return p2;
}

nodeptr bstree::srr(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(bsheight(p1->left), bsheight(p1->right)) + 1;
	p2->height = max(p1->height, bsheight(p2->right)) + 1;
	return p2;
}


nodeptr bstree::drl(nodeptr &p1)
{
	p1->left = srr(p1->left);
	return srl(p1);
}

nodeptr bstree::drr(nodeptr &p1)
{
	p1->right = srl(p1->right);
	return srr(p1);
}

int bstree::nonodes(nodeptr p)
{
	int count = 0;
	if (p != NULL)
	{
		nonodes(p->left);
		nonodes(p->right);
		count++;
	}
	return count;

}
