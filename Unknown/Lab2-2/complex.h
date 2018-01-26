/* Evan Eberhardt
Nicholas Pulido
COEN 70 LAB 2
*/

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex{
public:
	Complex(double r=0.0, double i=0.0);
	void setR(double);
	void setI(double);
	int getR() const;
	int getI() const;
	friend Complex operator* (const Complex&, const Complex&);
	friend Complex operator+ (const Complex&, const Complex&);
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);

private:
	double r;
	double i;
}; // creates the Complex class used in other functions

#endif