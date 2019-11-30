#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>


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
		num = numerator;
		den = denominator;
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



private:

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
	c.num = l.Numerator() * r.Denominator();
	c.den = l.Denominator() * r.Numerator();
	return c;
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

int main() {
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 4;
		}
	}

	cout << "OK" << endl;
	system("pause");
	return 0;
}
