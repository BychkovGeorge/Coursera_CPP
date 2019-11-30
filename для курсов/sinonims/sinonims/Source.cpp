#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

//class sinonim
//{
//public:
//	string word1;
//	string word2;
//};

int main()
{
	int N;
	int count = 0;
	map<string, set<string>> slo;
	// vector<sinonim> slovar;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string com;
		cin >> com;
		if (com == "ADD")
		{
			string w1, w2;
			// sinonim S;
			cin >> w1 >> w2;
			slo[w1];
			slo[w2];
			if (slo[w1].count(w2) == 0)
			{
				if (slo[w2].count(w1) == 0)
				{
					slo[w1].insert(w2);
					slo[w2].insert(w1);
				}
			}
		}
		else if (com == "COUNT")
		{
			string word;
			cin >> word;
			cout << slo[word].size() << endl;
		}
		else if (com == "CHECK")
		{
			string w1, w2;
			cin >> w1 >> w2;
			if (slo[w1].count(w2) == 0)
			{
				if (slo[w2].count(w1) == 0)
				{
					cout << "NO" << endl;
				}
			}
			else
				cout << "YES" << endl;
					
		}
	}
	return 0;
}