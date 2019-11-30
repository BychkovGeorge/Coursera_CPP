#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{
	int N, c = 0;
	string change;
	int j;
	cin >> N;
	vector<bool> line;
	for (int i = 0; i < N; i++)
	{
		cin >> change;
		if (change != "WORRY_COUNT")
		{
			cin >> j;
			if (change == "WORRY")
			{
			
				line[j] = true;
			}
			else if (change == "QUIET")
			{
				line[j] = false;
			}
			else if (change == "COME")
			{
				line.resize(line.size() + j);
			}
		}
		else if (change == "WORRY_COUNT")
		{
			for (int a = 0; a < line.size(); a++)
			{
				if (line[a] == true)
					c++;
			}
			cout << c << endl;
			c = 0;
		}
	}
	system("pause");
	return 0;
}