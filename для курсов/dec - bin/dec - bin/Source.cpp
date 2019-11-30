#include <iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int number;
	cin >> number;
	string decNumber;
	while (number)
	{
		decNumber += !(number % 2) ? '0' : '1';
		number /= 2;
	}
	reverse(decNumber.begin(), decNumber.end());
	cout << decNumber << "\n";
	system("pause");
	return 0;


}