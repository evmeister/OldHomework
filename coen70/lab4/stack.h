//Evan Eberhardt
//Ryan Nakagawa
#include <iostream>
#include <cstdlib>

using namespace std;

class List{
	public:
		List(); //Constructor
		~List(); //Destructor
		List(const List&); //Copy CTOR
		const List& operator=(const List&); //Assignment Operator
		friend ostream& operator<<(ostream&, const List&); //output
		void insert(const double&); //inserts item to list
		double pop(); //popping
		class node{
			public:
				node(double, node*);
				double data;
				node* next;
		};
		int size;
	private:
		node* list;
		node* cursor;
};
