#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;
	ifstream input("input.txt");
	while (getline(input, line))
	{
		cout << line << endl;
	}
	return 0;
}