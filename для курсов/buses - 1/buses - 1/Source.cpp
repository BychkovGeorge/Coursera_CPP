#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class line {
public:
	string bus;
	vector<string> stops;
};

int main()
{
	// line L;
	// map<string, vector<string>> bus;
	vector<string> stop;
	string S;
	vector<line> lines, lines1;
	int N;
	string com;
	cin >> N;
	for (int q = 0; q < N; q++)
	{
		cin >> com;
		if (com == "NEW_BUS")
		{
			line L;
			// lines.push_back(L);
			string number;
			cin >> number;
			L.bus = number;
			int count;
			cin >> count;
			for (int i = 0; i < count; i++)
			{
				cin >> S;
				L.stops.push_back(S);
			}
			lines.push_back(L);
		}
		else if (com == "BUSES_FOR_STOP")
		{
			string st;
			int counter = 0;
			cin >> st;
			for (int i = 0; i < lines.size(); i++)
			{
				for (int j = 0; j < lines[i].stops.size(); j++)
				{
					if (lines[i].stops[j] == st)
					{
						cout << lines[i].bus << " ";
						counter++;
					}
				}
			}
			if (counter == 0)
				cout << "No stop" << endl;
			else
				cout << endl;
		}
		else if (com == "STOPS_FOR_BUS")
		{
			string bu;
			cin >> bu;
			int pointer = 0, PO = 0;
			for (int i = 0; i < lines.size(); i++)
			{
				if (lines[i].bus == bu)
				{
					for (int j = 0; j < lines[i].stops.size(); j++)
					{
						cout << "Stop " << lines[i].stops[j] << ": ";
						for (int k = 0; k < lines.size(); k++)
						{
							for (int z = 0; z < lines[k].stops.size(); z++)
							{
								if ((lines[k].stops[z] == lines[i].stops[j]) && (lines[k].bus != bu))
								{
									cout << lines[k].bus << " ";
									pointer++;
								}
							}
						}
						if (pointer == 0)
							cout << "no interchange" << "\n";
						else
							cout << "\n";
						pointer = 0;
					}
					PO++;
				}
				
			}
			if (PO == 0)
			{
				cout << "No bus" << endl;
			}
		}
		else if (com == "ALL_BUSES")
		{
			line temp;
			if (lines.size() == 0)
				cout << "No buses" << endl;
			else
			{
				for (int r = 0; r < lines.size(); r++)
				{
					lines1.push_back(lines[r]);
				}


				for (int o = 0; o < lines1.size() - 1; o++) {
					for (int p = 0; p < lines1.size() - o - 1; p++) {
						if (lines1[p].bus > lines1[p + 1].bus) {
							// меняем элементы местами
							temp = lines1[p];
							lines1[p] = lines1[p + 1];
							lines1[p + 1] = temp;
						}
					}
				}


				for (int i = 0; i < lines1.size(); i++)
				{
					cout << "Bus " << lines1[i].bus << ": ";
					for (int j = 0; j < lines1[i].stops.size(); j++)
					{
						cout << lines1[i].stops[j] << " ";
					}
					cout << endl;
				}
			}
			lines1.clear();
		}
	}
	system("pause");

	return 0;
}