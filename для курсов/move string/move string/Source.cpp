#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination)
{
	for (int i = 0; i < source.size(); i++)
	{
		destination.push_back(source[i]);
	}
	source.clear();
}

int main()
{
	vector<string> source = { "fd", "ds" };
	vector<string> destination = { "eue" };
	MoveStrings(source, destination);
	for (int i = 0; i < destination.size(); i++)
		cout << destination[i] << "\n";
	system("pause");
}