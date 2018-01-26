#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
public:
	/**
	Constructs a fraction with numerator 0 and denominator 1.
	*/
	Fraction();

	/**
	Constructs a fraction with numerator t and denominator 1.
	@param t the numerator for the fraction
	*/
	Fraction(int t);

	/**
	Constructs a fraction with given numerator and denominator.
	@param t the initial numerator
	@param b the initial denominator
	*/
	Fraction(int t, int b);

	/**
	Returns the numerator.
	@return the numerator value
	*/
	int get_num() const;

	/**
	Returns the denominator.
	@return the denominator value
	*/
	int get_denom() const;

	/**
	Updates a fraction by adding in another fraction value.
	@param right the fraction to be added
	@return the updated fraction value
	*/
	Fraction& operator+=(const Fraction& right);

	//addition as friend function
	friend Fraction operator+(Fraction left, Fraction right);

	/**
	Compares one fraction value to another.
	Result is negative if less than right, zero if equal, and
	positive if greater than right.
	@param right the fraction to be compared against
	*/
	int compare(const Fraction& right) const;
private:
	/**
	Places the fraction in least common denominator form.
	*/
	void normalize();

	/**
	Computes the greatest common denominator of two integer values.
	@param n the first integer
	@param m the second integer
	*/
	int gcd(int n, int m);

	int top;
	int bottom;
};



Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& value);

bool operator<(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator>(const Fraction& left, const Fraction& right);

ostream& operator<<(ostream& out, const Fraction& value);
istream& operator>>(istream& in, Fraction& r);


int main()
{
	// Test constructors
	Fraction a;  // Value is 0/1
	Fraction b(4);  // Value is 4/1
	Fraction c(6, 8);  // Value is 6/8, which is converted to 3/4
	
	cout << "Constructed values " << a << " " << b << " " << c << "\n";
	cout << "Value of c is " << c.get_num() << "/"
		<< c.get_denom() << "\n";
	// Test arithmetic instructions
	Fraction d = b + c;
	cout << "4 + 3/4 is " << d << "\n";
	d = b - c;
	cout << "4 - 3/4 is " << d << "\n";
	Fraction e = (b + (-c));
	cout << e << " done with negation\n";
	if (d == e)
		cout << "Subtraction test successful\n";
	a = Fraction(6, 8);
	b = Fraction(7, 8);
	if (a < b)
		cout << "Compare successful\n";
	int n;
	cin >> n;
	return 0;
}

int Fraction::gcd(int n, int m)
{
	// Euclid's Greatest Common Divisor algorithm.
	assert((n > 0) && (m > 0));
	while (n != m)
	{
		if (n < m)
			m = m - n;
		else
			n = n - m;
	}
	return n;
}

Fraction::Fraction(int t, int b) : top(t), bottom(b)
{
	normalize();
}

Fraction::Fraction() : top(0), bottom(1) { }

Fraction::Fraction(int t) : top(t), bottom(1) { }

int Fraction::get_num() const
{
	return top;
}

int Fraction::get_denom() const
{
	return bottom;
}

void Fraction::normalize()
{
	// Normalize fraction by
	// (a) moving sign to numerator
	// (b) ensuring numerator and denominator have no common divisors
	int sign = 1;
	if (top < 0)
	{
		sign = -1;
		top = -top;
	}
	if (bottom < 0)
	{
		sign = -sign;
		bottom = -bottom;
	}
	assert(bottom != 0);
	int d = 1;
	if (top > 0) d = gcd(top, bottom);
	top = sign * (top / d);
	bottom = bottom / d;
}




Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result(left.get_num() * right.get_denom()
		+ right.get_num() * left.get_denom(),
		left.get_denom() * right.get_denom());
	return result;
}


Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result(left.get_num() * right.get_denom()
		- right.get_num() * left.get_denom(),
		left.get_denom() * right.get_denom());
	return result;
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result(left.get_num() * right.get_num(),
		left.get_denom() * right.get_denom());
	return result;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result(left.get_num() * right.get_denom(),
		left.get_denom() * right.get_num());
	return result;
}

Fraction operator-(const Fraction& value)
{
	Fraction result(-value.get_num(), value.get_denom());
	return result;
}

int Fraction::compare(const Fraction& right) const
{
	return get_num() * right.get_denom()
		- get_denom() * right.get_num();
	// Return the numerator of the difference
}

bool operator<(const Fraction& left, const Fraction& right)
{
	return left.compare(right) < 0;
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return left.compare(right) <= 0;
}

bool operator==(const Fraction& left, const Fraction& right)
{
	return left.compare(right) == 0;
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return left.compare(right) != 0;
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	return left.compare(right) >= 0;
}

bool operator>(const Fraction& left, const Fraction& right)
{
	return left.compare(right) > 0;
}

ostream& operator<<(ostream& out, const Fraction& value)
{
	out << value.get_num() << "/" << value.get_denom();
	return out;
}

istream& operator>>(istream& in, Fraction& r)
{
	int t, b;
	// Read the top
	in >> t;
	// If there is a slash, read the next number
	char c;
	in >> c;
	if (c == '/')
		in >> b;
	else
	{
		in.unget();
		b = 1;
	}
	r = Fraction(t, b);
	return in;
}


Fraction& Fraction::operator+=(const Fraction& right)
{
	top = top * right.get_denom() + bottom * right.get_num();
	bottom *= right.get_denom();
	normalize();
	return *this;
}
