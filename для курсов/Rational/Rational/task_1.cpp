#include <iostream>



using namespace std;

//int NOD( int a,  int b)
//{
//	unsigned int c;
//	if (a < 0)
//		a *= -1;
//	if (b < 0)
//		b *= -1;
//	while (a && b)
//		if (a >= b)
//			a %= b;
//		else
//			b %= a;
//	c = a | b;
//	return c;
//}

class Rational {
public:
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
	 int num;
	 int den;
};


