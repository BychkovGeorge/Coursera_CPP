#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s, pr = "f";
	char c = pr[0];
	int counter = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
		{
			if (++counter == 2)
				cout << i;
		}
	}
	if (counter == 0)
	{
		cout << -2;
	}
	else if (counter == 1)
	{
		cout << -1;
	}
	system("pause");
	return 0;
}