#include "list.h"

int main()
{
		List x;

		x.insert(5);
		x.insert(4);
		x.insert(3);
		x.insert(2);

		List y(x);

		y.insert(1);

		List z = y;

		z.insert(0);

		cout << "x: " << x << endl; //should print out x: 5, 4, 3, 2,
		cout << "y: " << y << endl; //should print out y: 5, 4, 3, 2, 1,
		cout << "z: " << z << endl; //shoudl print out z: 5, 4, 3, 2, 1, 0,

}
