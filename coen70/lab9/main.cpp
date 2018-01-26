#include "RBTree.h"


int main()
{
	RBTree tree;

	tree.addNode(10);
	tree.addNode(85);
	tree.addNode(15);
	tree.addNode(70);
	tree.addNode(20);
	tree.addNode(60);
	tree.addNode(30);
	tree.addNode(50);

	tree.printTree(); //should output 30 15 10 20 70 60 50 85
	cout << endl;
}
