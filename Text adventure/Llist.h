#ifndef LLIST_H
#define LLIST_H
#include<iostream>
#include "Item.h"
//done


using namespace std;

class Llist{
	typedef int data;
    private:

        class Node{

			public:
				Item it;
				data value = it.getid();
                Node *next;
                Node():next(0){}
                Node(data val):value(val),next(0){}
				Node(data val, Item newI) :value(val), next(0), it(newI) {}
        };
        Node *first;
        int mySize;
        Node * pos2Ptr(int pos){
            Node *temp = first; --pos;
            while(--pos != 0) temp = temp->next;
        return temp;
        }

    int posSearch(int num){//finds the position of a value in the list(used in the erase function)
        int pos=1;
        Node * tempNode = first;
        while(tempNode->value!=num&&pos<=mySize){
            tempNode = tempNode->next;
            pos++;
        }
        return pos;
    }

    Node * search(data num){//determines if a number is located in a list and returns a pointer to it
        Node * tempNode = first;
        int count=1;
        while(tempNode->value!=num&&count<=mySize){
            tempNode = tempNode->next;
            count++;
        }
        return tempNode;

    }
    public:

        Llist():first(0),mySize(0){first = new Node(0);};// constructor

		~Llist();

        Llist(Llist &L){// copy constructor
           if (L.first!=0){
                first = new Node (L.first->value);
                Node * origTemp = L.first;
                Node *copyTemp = first;

                while (origTemp->next!=0){
                    copyTemp->next = new Node(origTemp->next->value);
                    copyTemp=copyTemp->next;
                    origTemp=origTemp->next;
                }

           }
            else first = 0;
       };

       void erase (data num){// erase the item indexed by the argument
        int pos = posSearch(num);
        if(pos<=mySize){
            Node * temp; Node * node2Delete;
            if (pos ==1){
                node2Delete = first;
                first = first->next;
            }
            else {
                temp = pos2Ptr(pos);
                node2Delete= temp->next;
                temp->next = temp->next->next;
            }
            delete node2Delete;
            mySize--;
        }
       }

    Item find(data num){//returns a copy of the item
        Node * tempNode = search(num);
        return(tempNode->it);
    }

    void insert (data num, Item itInsert){//insert item into list
        int pos = mySize+1;
        Node *newNode = new Node(num,itInsert);
        Node *temp;
        if (pos>mySize){
            temp =first;
        }

        if(pos == 1) {
            newNode->next = first;
            first = newNode;

        }
		else {
			temp = pos2Ptr(pos);
            newNode->next= temp->next;
			temp->next = newNode;
        }
        mySize++;
    }

        bool ifEmpty(){// checks if list is empty
            if (mySize==0){
                return 1;

            }
            else return 0;
        }

        inline void operator=(Llist & L){
           if (L.first!=0){
                this->first = new Node (L.first->value,L.first->it);
                Node * origTemp = L.first;
                Node *copyTemp = this->first;
				this->mySize = L.mySize;

                while (origTemp->next!=0){
                    copyTemp->next = new Node(origTemp->next->value,origTemp->next->it);
                    copyTemp=copyTemp->next;
                    origTemp=origTemp->next;
                }

           }
            else this->first = 0;
       };


    void display(ostream & out){
        if(!ifEmpty()){
            Node *temp = first;
            while (temp->next != 0 ){cout<<temp->it <<endl; temp = temp->next;}
        }
        else cout<<"list is empty"<<endl<<endl;
    }




    friend ostream & operator<<(ostream &out, Llist &P);
};

inline ostream & operator<<(ostream &out, Llist &P) { P.display(out); return out; }


#endif // LLIST_H