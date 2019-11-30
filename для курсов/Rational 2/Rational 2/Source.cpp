#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>


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

int main() {
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	system("pause");
	return 0;
}
