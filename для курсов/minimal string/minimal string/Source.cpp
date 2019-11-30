#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	if ((a < b) && (a < c))
		cout << a << "\n";
	else if ((b < a) && (b < c))
		cout << b << "\n";
	else if ((c < a) && (c < b))
		cout << c << "\n";
	else if ((a == b) && (a == c))
		cout << c << "\n";
	else if ((a == b) && (a < c))
		cout << a << "\n";
	else if ((a == b) && (a > c))
		cout << c << "\n";
	else if ((a==c)&&(a<b))
		cout << a << "\n";
	else if ((a == c) && (a>b))
		cout << b << "\n";
	else if ((b == c) && (b<a))
		cout << b << "\n";
	else if ((b == c) && (b>a))
		cout << a << "\n";
	system("pause");
	return 0;
}