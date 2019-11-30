#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v)
{
	int N = v.size();
	for (int i = 0; i < N / 2; i++)
	{
		int tmp = v[i];
		v[i] = v[N - i - 1];
		v[N - i - 1] = tmp;
	}
}

int main()
{
	vector<int> b = { 1, 2, 5, 4 };
	Reverse(b);
	for (int f = 0; f < b.size(); f++)
	{
		cout << b[f] << "\n";
	}
	system("pause");
	return 0;
}