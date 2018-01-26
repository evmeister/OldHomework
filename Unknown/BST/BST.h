/*
   Daniel Yeh
   Evan Eberhardt
   COEN 70
   Homework 7: Implement a BST ADT
*/
#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <cstdlib>
#include <iostream>

using namespace std;

class BST{
	protected:
		struct node{
			node(int v = int(), node* l=NULL, node* r=NULL):d(v), lc(l), rc(r) {};
			bool isLeaf(node* t){
			    if(t!=NULL && t->lc==NULL && t->rc==NULL)
                    return true;
                else
                    return false;
            }
            //getMax: returns and int for the purposes of remove
			int getMax(node* t) {while(t->rc!=NULL) t=t->rc; return t->d;}
			int d;
			node* lc;
			node* rc;
		};
		node *r;
		int size;
		void clear();
		void clear(node*);
		node* copy(node*);
		int depth(node*);
		void print(node*&, int);
	public:
		BST(){r=NULL;}
		BST(const BST& other) {r=NULL; *this = other;}
		~BST() {clear();}
		BST& operator=(const BST& other);
		bool insert(const int&);
		bool rmv(const int&, node*&);
		bool remove(const int& x){return rmv(x, this->r);}
		bool contains(const int&);
		int getSize() {return size;}
        int getdepth() {return this->depth(this->r);}
		void printbst() {print(this->r, 0);}

};

#endif
