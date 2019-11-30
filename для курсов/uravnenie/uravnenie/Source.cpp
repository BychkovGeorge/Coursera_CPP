#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a, b, c, d, x1, x2;
	cin >> a >> b >> c;
	if ((a == 0)&&(c!=0)&&(b!=0))
	{
		x1 = -c / b;
		cout << x1 << "\n";
		system("pause");
		return 0;
	}
	else if ((b == 0) && (c < 0) && (a > 0))
	{
		x1 = sqrt(-c / a);
		x2 = -sqrt(-c / a);
		cout << x1 << "\n" << x2 << "\n";
		system("pause");
	}
	else if ((b == 0) && (c > 0) && (a < 0))
	{
		x1 = sqrt(-c / a);
		x2 = -sqrt(-c / a);
		cout << x1 << "\n" << x2 << "\n";
		system("pause");
	}
	else if ((b == 0) && (c > 0) && (a > 0))
	{
		system("pause");
		return 0;
	}
	else if ((b == 0) && (c < 0) && (a < 0))
	{
		system("pause");
		return 0;
	}
	else if ((a == 0) && (b == 0))
	{
		system("pause");
		return 0;
	}
	else 
	{
		d = b * b - 4 * a * c;
		if (d > 0)
		{
			x1 = (-b + sqrt(d)) / (2 * a);
			x2 = (-b - sqrt(d)) / (2 * a);
			cout << x1 << "\n" << x2 << "\n";
			system("pause");
			return 0;
		}
		else if (d == 0)
		{
			x1 = -b / (2 * a);
			cout << x1 << "\n";
			system("pause");
			return 0;
		}
		else if (d < 0)
		{
			system("pause");
			return 0;
		}
	}
	
}