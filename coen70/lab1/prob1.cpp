/* HelloWorldExample.cpp */
#include <iostream>
#include <string>

using namespace std;

struct object {
	string* s;
};

int main()
{
	object A, B;
	A.s = new string;
	B.s = new string;
	*A.s = "Hello World"; // A has "Hello World"
	*B.s = *A.s; // B has "Hello World"
	*A.s = "Goodbye"; // A has Goodbye"
	cout << *A.s << endl;
	cout << *B.s << endl;
	return 0;
}
