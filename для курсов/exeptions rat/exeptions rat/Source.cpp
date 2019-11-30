#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <exception>


using namespace std;

int NOD(int a, int b)
{
	unsigned int c;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	while (a && b)
		if (a >= b)
			a %= b;
		else
			b %= a;
	c = a | b;
	return c;
}



class Rational {
public:

	int num;
	int den;


	Rational() {
		num = 0;
		den = 1;
	}

	Rational(int numerator, int denominator) {
		if (denominator == 0)
			throw invalid_argument("");
		else {
			num = numerator;
			den = denominator;
		}
	}

	int Numerator() const {
		if ((num > 0 && den > 0) || (num < 0 && den > 0))
			return num / NOD(num, den);
		else if (num > 0 && den < 0)
			return (num / NOD(num, den)) * (-1);
		else if (num == 0)
			return num;
		else if (num < 0 && den < 0)
			return num / NOD(den, num) * (-1);
	}

	int Denominator() const {
		if ((num > 0 && den > 0) || (num < 0 && den > 0))
			return den / NOD(num, den);
		else if (num > 0 && den < 0)
			return (-1) * (den / NOD(num, den));
		else if (num == 0)
			return 1;
		else if (num < 0 && den < 0)
			return den / NOD(den, num) * (-1);
	}





};

bool operator == (Rational lhs, Rational rhs)
{
	if ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator()))
		return true;
	else
		return false;
}

Rational operator + (const Rational& l, const Rational& r)
{
	Rational c;
	c.num = l.Numerator() * r.Denominator() + r.Numerator() * l.Denominator();
	c.den = r.Denominator() * l.Denominator();
	return c;
}

Rational operator - (const Rational& l, const Rational& r)
{
	Rational c;
	c.num = l.Numerator() * r.Denominator() - r.Numerator() * l.Denominator();
	c.den = r.Denominator() * l.Denominator();
	return c;
}

Rational operator * (const Rational& l, const Rational& r)
{
	Rational c;
	c.num = l.Numerator() * r.Numerator();
	c.den = r.Denominator() * l.Denominator();
	return c;
}

Rational operator / (const Rational& l, const Rational& r)
{
	Rational c;
	if (r.Numerator() == 0)
		throw domain_error("");
	else {
		c.num = l.Numerator() * r.Denominator();
		c.den = l.Denominator() * r.Numerator();
		return c;
	}
}

ostream& operator << (ostream& stream, const Rational& r)
{
	stream << r.Numerator() << "/" << r.Denominator();
	return stream;
}

istream& operator >> (istream& stream, Rational& r)
{
	stream >> r.num;
	stream.ignore(1);
	stream >> r.den;
	return stream;
}

bool operator < (const Rational& r, const Rational l)
{
	Rational c;
	c = r - l;
	if (c.Numerator() < 0)
		return true;
	else
		return false;
}

bool operator > (const Rational& r, const Rational l)
{
	Rational c;
	c = r - l;
	if (c.Numerator() > 0)
		return true;
	else
		return false;
}

bool operator != (Rational lhs, Rational rhs)
{
	if ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator()))
		return false;
	else
		return true;
}

int main() {
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error&) {
	}

	cout << "OK" << endl;
	system("pause");
	return 0;
}