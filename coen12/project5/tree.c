/*Evan Eberhardt
 * Project 5
 * creates and destroys trees, gets data, and sets subtrees */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
#include"tree.h"
typedef struct tree TREE;
struct tree{
	int data;
	TREE *left, *right, *parent;
};
void detach(TREE *child);
/*createTree
 * This function allocates the root of a tree and sets its pointers.
 * This is O(1)
 */
TREE *createTree(int data, TREE *left, TREE *right)
{
	TREE *root;
	root=malloc(sizeof(TREE));
	assert(root!=NULL);
	root->data=data;
	root->right=right;
	if(root->right!=NULL)
	{
		detach(right);
		root->right->parent=root;
	}
	root->left=left;
	if(root->left!=NULL)
	{
		detach(left);
		root->left->parent=root;
	}
	root->parent=NULL;
	return root;
}
/*destroyTree
 *This function deallocates an entire tree.
 *This is O(n)
 */
void destroyTree(TREE *root)
{
	if(root!=NULL)
	{
		destroyTree(root->left);
		destroyTree(root->right);
		free(root);
	}
	return;
}
/*detach
 * These helper function sets the left or right child's parent to null to detach it from its old parent.
 * It compares the children's data to see if the child is the left or right child.
 * This is O(1)
 */
void detach(TREE *child)
{
	if(child->parent!=NULL)
	{
		if(child->parent->left->data==child->data)
		{
			child->parent->left=NULL;
		}
		else
		{
			child->parent->right=NULL;
		}
	}
	return;
}
/*getData
 * This function returns the root's data
 * This is O(1)
 */
int getData(TREE *root)
{
	assert(root!=NULL);
	int x;
	x=root->data;
	return x;
}
/*getLeft
 * This function returns a pointer to the root's left subtree.
 * This is O(1)
 */
TREE *getLeft(TREE *root)
{
	assert(root!=NULL);
	return root->left;
}
/*getRight
 * This function returns a pointer to the root's right subtree.
 * This is O(1)
 */
TREE *getRight(TREE *root)
{
	assert(root!=NULL);
	return root->right;
}
/*getParent
 * This function returns a pointer to the root's parent.
 * This is O(1)
 */
TREE *getParent(TREE *root)
{
	assert(root!=NULL);
	return root->parent;
}
/*setLeft
 * This function changes the pointers of root's left subtree. 
 * This is O(1)
 */
void setLeft(TREE *root, TREE *left)
{
	assert(root!=NULL);
	if(root->left!=NULL)
		root->left->parent=NULL;
	root->left=left;
	if(root->left!=NULL);
	{
		detach(left);	
		root->left->parent=root;
	}
	return;
}
/*setRight
 * This function changes the pointers of root's right subtree.
 * This is O(1)
 */
void setRight(TREE *root, TREE *right)
{
	assert(root!=NULL);
	if(root->right!=NULL)
		root->right->parent=NULL;
	root->right=right;
	if(root->right!=NULL)
	{
		detach(right);
		root->right->parent=root;
	}
	return;
}
