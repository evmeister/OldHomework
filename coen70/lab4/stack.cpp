//Evan Eberhardt
//Ryan Nakagawa

#include <iostream>
#include "stack.h"
#include <cstdlib>

using namespace std;

double List::pop(){
	double p=cursor->data;
	delete cursor;
	cursor=list;
	while(cursor->next!=NULL)
		cursor=cursor->next;
	size--;
	return p;	
}

List::List(){ //Default Constructor
	size=0;
	list=NULL;
	cursor=list;
}
List::~List(){ //Destructor
	if(list!=NULL && cursor!=NULL){
		node* temp;
		temp=list->next;
		while(list!=cursor){		
			delete list;
			list=temp;
			temp=list->next;
		}
		delete cursor;
	}
}
List::node::node(double x, node* n){ //Node Constructor
	data=x;
	next=n;
}
void List::insert(const double& x){ //Insert function
	node* node= new List::node(x, NULL);
	if(size==0){ //Check if empty
		list=node;
		cursor=list;
		size++;
		return;
	}
	else
	cursor->next=node;
	cursor=node;
	size++;	
}
List::List(const List& other){ //Copy Constructor
	list=NULL;
	size=0; //Needs to equal 0 initially because so that the if statement in insert doesnt break
	cursor=list;
	node* temp;
	temp=other.list;
	while(temp!=NULL){
		insert(temp->data);
		temp=temp->next;
	}
	size=other.size;
}
const List& List::operator=(const List& other){ //Assignment operator
	if(this==&other) //Check for self assignment
		return *this;
	if(this->list!=NULL) //Check if empty
		this->~List();
	this->cursor=NULL;
	this->list=NULL;
	size=0; //Must equal 0 so that the if statement in the insert function doesn't break
	list=NULL;
	cursor=list;
	node* temp;
	temp=other.list;
	while(temp!=NULL){
		insert(temp->data);
		temp=temp->next;
	}
	size=other.size; //;_;
	return *this;
}
ostream& operator<<(ostream& o, const List& n){ //Output operator
	List::node* temp;
	temp = n.list; 
	while (temp != NULL){
		o<< temp->data << ",";
		temp=temp->next;
	}
	return o; 
} 
