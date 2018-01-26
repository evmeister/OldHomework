/*SphereExample.cpp*/
#include <iostream>
using namespace std;

const double PI = 3.14159265359;

void GetRadius(double & radius);
void ShowResults(double rad, double area, double vol);

int main()
{
	cout<< "Program computes surface area and volume of a sphere. \n";
	double radius,				// radius of sphere
		   surfaceArea=0,		// its surface area
		   volume=0;			// its volume

	GetRadius(radius);
	surfaceArea = 4.0 * PI * radius * radius;
	volume = surfaceArea * radius / 3.0;

	ShowResults(radius, surfaceArea, volume);
}

void GetRadius(double& rad)
{
	cout << "Enter radius of sphere:";
	cin >> rad;
}

void ShowResults(double rad, double area, double vol)
{
	cout << "Radius of shpere is " << rad << "inches\n";
	cout << "Its surface area is " << area << "sq. inches\n"
		 << "Its volume is " << vol << " cubic inches.\n\n";
}
