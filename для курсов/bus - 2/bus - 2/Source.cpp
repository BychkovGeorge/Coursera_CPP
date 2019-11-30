#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;



int main()
{
	set<string> marsh;
	vector<set<string>> stops;
	int a = 0;
	int N;
	cin >> N;
	int r = 0;
	for (int i = 0; i < N; i++)
	{
		int col;
		cin >> col;
		for (int p = 0; p < col; p++)
		{
			string stop;
			cin >> stop;
			marsh.insert(stop);
		}
		for (int j = 0; j < stops.size(); j++)
		{
			if (stops[j] == marsh)
			{
				a = j + 1;
			}
		}
		if (a == 0)
		{
			stops.push_back(marsh);
			cout << "New bus " << r + 1 << endl;
		}
		else
		{
			cout << "Already exists for " << a << endl;
			r--;
		}
		marsh.clear();
		a = 0;
		r++;

	}
	system("pause");
	return 0;
}