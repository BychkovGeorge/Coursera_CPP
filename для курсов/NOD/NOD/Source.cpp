#include <iostream>

using namespace std;

int main()
{
	unsigned int a, b, c;
	cin >> a >> b;
	while (a && b)
		if (a >= b)
			a %= b;
		else
			b %= a;
	c = a | b;
	cout << c;
	system("pause");
	return 0;

}