#include <iostream>
#include <vector>
#include <string>

using namespace std;

class day
{
public:
	vector<string> deals;
	size_t number = 0;
};

int main()
{
	vector<int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	vector<day> month;
	day d;
	int count = 0;
	for (int i = 0; i < days[0]; i++)
	{
		month.push_back(d);
	}
	int N;
	string com;
	cin >> N;
	for (int j = 0; j < N; j++)
	{
		cin >> com;
		if (com == "ADD")
		{
			int k;
			string name;
			cin >> k >> name;
			month[k - 1].deals.push_back(name);
			month[k - 1].number++;
		}
		else if (com == "NEXT")
		{
			if (days[count % 12] > days[(count + 1) % 12])
			{
				if (days[count % 12] - days[(count + 1) % 12] < 2)
				{
					for (int q = 0; q < month[30].number; q++)
						month[29].deals.push_back(month[30].deals[q]);
					month[29].number += month[30].number;
				}
				else if (days[count % 12] - days[(count + 1) % 12] > 2)
				{
					for (int z = 0; z < month[30].number; z++)
					{
						month[27].deals.push_back(month[30].deals[z]);
						
					}
					for (int z = 0; z < month[29].number; z++)
					{
						month[27].deals.push_back(month[29].deals[z]);

					}
					for (int z = 0; z < month[28].number; z++)
					{
						month[27].deals.push_back(month[28].deals[z]);

					}
					month[27].number += month[30].number;
					month[27].number += month[29].number;
					month[27].number += month[28].number;
				}
			}
			month.resize(days[(count + 1)%12]);
			count++;
		}
		else if (com == "DUMP")
		{
			size_t y;
			cin >> y;
			cout << month[y - 1].number <<" ";
			for (int u = 0; u < month[y - 1].number; u++)
				cout << month[y - 1].deals[u] << " ";
			cout << endl;

		}
	}
	return 0;
}