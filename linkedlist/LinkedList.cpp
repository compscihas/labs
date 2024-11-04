/*
 * LinkedList.h
 *
 *  Created on: Jan 30, 2019, updated 4/9/2024
 *      Author: slupoli
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#ifndef _LINKED_LINKED_H_
#define _LINKED_LINKED_H_

struct Node
{
	string name;
	int test_grade;
	Node * link;
	
	friend ostream &operator << (ostream &os, const Node &x);
};

ostream &operator << (ostream &os, const Node &x)
{
	os << "%%%%%%%%%%%%%" << endl;
	os << x.name << endl;
	os << x.test_grade<< endl;
	return os;
}

class Linked_List
{
// this does not follow the complete class profile (rule of 3)
public:
	Linked_List();
	~Linked_List();
	void insert(string n, int score);
	void remove(string target);
	void print_head(); // print just the first value
	void print_list();
	bool hasValue(string n); // find a name
	
private:
	bool isEmpty();
	Node *FRONT, *REAR, *CURSOR, *INSERT, *PREVIOUS;
};

#endif

/*
 * LinkedList.cpp
 *
 *  Created on: Jan 30, 2019, updated 4/9/2024
 *      Author: slupoli
 */

Linked_List::Linked_List()
{
	FRONT = nullptr;
	REAR = nullptr;
	PREVIOUS = nullptr;
}

Linked_List::~Linked_List()
{
  while(FRONT != nullptr)
  {
      CURSOR = FRONT;
      FRONT = FRONT -> link; // moves FRONT up one Node
	  delete CURSOR; // deletes and return Node back to free memory!!!
  }
}

void Linked_List::insert(string n, int score)
{
	INSERT = new Node;
	INSERT -> link = nullptr; // being safe with the Node's link!!

	// collect information into INSERT Node
	INSERT -> name =  n; // must use strcpy to assign strings
	INSERT -> test_grade = score;

	if(isEmpty()) // first item in List
	{
		FRONT = INSERT;
	}
	else // else what?? When would this happen??
	{
		REAR -> link = INSERT;
	}
	REAR = INSERT;
}

void Linked_List::print_list( )
{
  // good for only a few Nodes in a list

	if(isEmpty())
	{
		cout << "No Nodes to display" << endl;
		return;
	}

	for(CURSOR = FRONT; CURSOR != nullptr; CURSOR = CURSOR-> link)
	{ cout << *CURSOR << endl; } // uses overloaded cout of Node
}

void Linked_List::remove(string target)
{
	// 3 possible places that NodeS can be removed from in the Linked List
	// FRONT
	// MIDDLE
	// REAR
	// all 3 condition need to be covered and coded

	// use Traversing to find TARGET

	PREVIOUS = nullptr;

	for(CURSOR = FRONT; CURSOR != nullptr; CURSOR = CURSOR-> link)
	{
		if(CURSOR->name == target) // match
		{ break; } // function will still continue, CURSOR will
	// mark Node to be removed
		else
		{ PREVIOUS = CURSOR; } // PREVIOUS marks what Node CURSOR is marking
	// JUST before CURSOR is about to move to the next Node
	}

	if(CURSOR == nullptr) { return; } // never found a match
	else
	{
		if((CURSOR == FRONT) && (CURSOR == REAR))
		{// TARGET Node was the first and ONLY in the list
			FRONT = nullptr;
			REAR = nullptr;
		}
		else if (CURSOR == FRONT) // TARGET Node was the first in the list
		{
			FRONT = FRONT -> link; // moves FRONT up one Node
		}// why no need for PREVIOUS??
		else if (CURSOR == REAR) // TARGET Node was the last in the list
		{ // will need PREVIOUS for this one
			PREVIOUS -> link = nullptr; // since this Node will become the last in the list
			REAR = PREVIOUS; // = REAR; // moves REAR into correct position in list
			PREVIOUS = nullptr; // previous is not used anymore
		}
		else // TARGET Node was the middle of the list
		{ // will need PREVIOUS also for this one
			PREVIOUS -> link = CURSOR-> link; // moves PREV Nodes' link to point where CURSOR Nodes' points
			// PREVIOUS->link = nullptr; // THIS IS OFF, connected incorrectly
			PREVIOUS = nullptr;
		}
		CURSOR->link = nullptr;
		delete CURSOR; // deletes and return Node back to free memory!!!
	}
}

bool Linked_List::isEmpty()
{
	if ((FRONT == nullptr) && (REAR == nullptr))	{ return true; }
	else { return false;}
}

bool Linked_List::hasValue(string target)
{
	PREVIOUS = nullptr;

	for(CURSOR = FRONT; CURSOR != nullptr; CURSOR = CURSOR-> link)
	{
		if(CURSOR->name == target) // match
		{ return true; } 
		else
		{ PREVIOUS = CURSOR; } // PREVIOUS marks what Node CURSOR is marking
	// JUST before CURSOR is about to move to the next Node
	}
	
	// if it reached here, never found it
	return false;
}

int main()
{
	Linked_List one;
	one.insert("Angela", 261);
	one.insert("Jack", 20);
	one.insert("Peter", 120);
	one.insert("Chris", 270);
	one.print_list();
	one.remove("Jack");
	one.print_list();
	one.remove("Angela");
	one.print_list();
	one.remove("Chris");
	one.print_list();
	cout << one.hasValue("Peter") << endl;
	cout << one.hasValue("Jack") << endl;
	
	Node* Hasan = new Node;
	Hasan -> name = "Hasan";

	cout << Hasan->name << endl;
	Hasan ->test_grade = 100;
	Node* Suley = new Node;
	Suley -> name = "Suley";
	Suley -> test_grade = 50;
	Node* Sam = new Node;
	Sam -> name= "Sam";
	Sam -> test_grade = 35;
	Node* Haris = new Node;
	Haris -> name = "Haris";
	Haris -> test_grade = 45;
	Hasan -> link = Suley;
	Suley -> link = Haris;
	Haris -> link = Sam;
	Sam -> link = nullptr;
	


	

	return 0;
}

