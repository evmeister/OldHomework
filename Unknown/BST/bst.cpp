#include "BST.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

BST& BST::operator=(const BST& other){
    if(this==&other)
        return *this;
    clear();
    r=copy(other.r);
    size=other.size;
    return *this;
}

void BST::clear(){
    clear(r);
}

void BST::clear(node* r){
    if(r==NULL)
        return;
    clear(r->lc);
    clear(r->rc);
    delete r;
    return;
}

BST::node* BST::copy(node* root){
    if(root==NULL)
        return NULL;
    return new node(root->d, copy(root->lc), copy(root->rc));
}

void BST::print(node*& r, int depth){
    if(r!=NULL){
        print(r->rc, depth+1);
        cout<<setw(4*depth)<<" "<<r->d<<endl;
        print(r->lc, depth+1);
    }
    return;
}

bool BST::insert(const int& x){
    node* t=r;
    while(t!=NULL){
        if(x<t->d){
            if(t->lc==NULL){
                t->lc= new node(x);
                return true;
            }
            t=t->lc;
        }
        else if(x>t->d){
            if(t->rc==NULL){
                t->rc=new node(x);
                return true;
            }
            t=t->rc;
        }
        else if(x==t->d){//dissallows duplicates
            cout<<x<<" is already present"<<endl;
            return false;
        }

    }
    r=new node(x);
    return true;
}

int BST::depth(node* r){
    if(r==NULL)
        return 0;
    if(r!=NULL && !r->isLeaf(r))
        return max(depth(r->lc),depth(r->rc))+1;
    return 1;
}

bool BST::rmv(const int& x, node*& p){
    node* trail=NULL; //Points to parent node; if not alerted to child's removal, program crashes
    int flag=0; //tracks if left or right child was removed
    if(p==NULL) //Check if tree is present
        return false;
    if(p->isLeaf(p) && p->d==x){ //theres only one node
        delete p;
        p=NULL;
        if(trail!=NULL && flag==2)
            trail->rc=NULL;
        else if(trail!=NULL && flag==1)
            trail->lc=NULL;
        return true;
    }
    node* temp=p;
    while(temp!=NULL && temp->d!=x){//search for the correct node
        if(temp->d<x){
            trail=temp;
            temp=temp->rc;
            flag=2;
        }
        else{
            trail=temp;
            temp=temp->lc;
            flag=1;
        }
    }
    if(temp==NULL) return false; //x isnt present
    if(temp->lc!=NULL){ //x has a left child
        int maxval=temp->lc->getMax(temp->lc); //saves value of max from subtree
        rmv(maxval, temp); //removes node with max from subtree
        temp->d=maxval; //replaces valude of temp with maxval
    }
    else if(temp->isLeaf(temp)){ //x is a leaf. recursive methods don't work at this point because flag and trail arent passed in
        delete temp;
        temp=NULL;
        if(trail!=NULL && flag==2)
            trail->rc=NULL;
        else if(trail!=NULL && flag==1)
            trail->lc=NULL;
        return true;
    }
    else{ //x has a right child only
        temp->d=temp->rc->d;
        temp->lc=temp->rc->lc;
        node* tt=temp->rc;
        temp->rc=temp->rc->rc;
        delete tt;
    }

    return true;
}

bool BST::contains(const int& x){
    node* temp=this->r;
    while(temp!=NULL && temp->d!=x){//search for the correct node
        if(temp->d<x)
            temp=temp->rc;
        else
            temp=temp->lc;
    }
    if(temp==NULL) return false;
    //if(temp->isLeaf(temp)) cout<<true; else cout<<false; //test of isLeaf function
    //if(temp->getMax(temp)->d==17) cout<<true; else cout<<false; //test if getMax if root passed in
    return true;
}



