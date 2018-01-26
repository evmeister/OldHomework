#include <iostream>

using namespace std;

class List{
	public:
		List(); //Constructor
		~List(); //Destructor
		List(const List&); //Copy CTOR
		const List& operator=(const List&); //Assignment Operator
		friend ostream& operator<<(ostream&, const List&); //output
		void insert(const int&); //inserts item to list
		class node{
			public:
				node(int, node*);
				int data;
				node* next;
		};
	private:
		node* list;
		int size;
		node* cursor;
};
