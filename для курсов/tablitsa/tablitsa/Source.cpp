#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream input("input.txt");
	int n, m;
	if (input) {
		input >> n >> m;
		vector<vector<int> > table(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				input >> table[i][j];
				cout << setw(10) << table[i][j];
				if (j != m - 1) {
					input.ignore(1);
					cout << " ";
				}
			}
			if (i != n - 1) {
				cout << endl;
			}
		}
	}
	return 0;
}