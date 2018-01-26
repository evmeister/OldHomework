/* Evan Eberhardt
Nicholas Pulido
COEN 70 LAB 2
*/

#include "complex.h"
#include <iostream>


using namespace std;

// CONSTRUCTORS
void Complex::setR(double a){ //sets the real number value to the first number input
	r=a;
}

void Complex::setI(double b){ //sets the imaginary number value to the second number
	i=b;
}

int Complex::getR() const{
	return r;
}

int Complex::getI() const{
	return i;
}

Complex::Complex(double a, double b){
	r=a;
	i=b;
}

// OPERATORS
Complex operator*(const Complex& a, const Complex& b){
	Complex v;
	v.r = (a.r * b.r - a.i * b.i);// multiplies the values of the real numbers and subtracts from the product of the imaginary numbers
	v.i = (a.r * b.i + a.i * b.r);
	return v;
}

Complex operator+(const Complex& a, const Complex& b){
	Complex d;
	d.r = a.r + b.r; //adds the real number values together
	d.i = a.i + b.i; //adds the imaginary values together
	return d;
}

ostream& operator<<(ostream& o, const Complex&f){
	o<<f.r<<"+"<<f.i<<"*i";
	return o;
}

istream& operator>>(istream& i, Complex& f){
	int a,b;
	char s;
	i>>a>>s>>b;
	f.setR(a);
	f.setI(b);
	return i;
}