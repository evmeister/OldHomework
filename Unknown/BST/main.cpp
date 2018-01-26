#include "BST.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    BST Dave;
    Dave.insert(10);
    Dave.insert(5);
    cout<<"depth test:   "<<Dave.getdepth()<<endl; //should be 2 at this point
    Dave.insert(15);
    Dave.insert(13);
    Dave.insert(17);
    cout<<"depth test:   "<<Dave.getdepth()<<endl; //should be 3 at this point
    Dave.insert(3);
    Dave.insert(7);
    Dave.printbst();
    cout<<endl;
    cout<<"contains 13:  "<<Dave.contains(13)<<endl; //Prints 1 if found
    cout<<"remove 13 test:  "<<Dave.remove(13)<<endl; //Prints 1 if successful
    cout<<"remove 15 test:  "<<Dave.remove(15)<<endl; //Prints 1 if successsful
    cout<<"remove 10 test:  "<<Dave.remove(10)<<endl; //prints 1 if successful
    cout<<endl;
    Dave.printbst();
    return 0;
}
