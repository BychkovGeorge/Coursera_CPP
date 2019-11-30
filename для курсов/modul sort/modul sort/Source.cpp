#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <clocale>
#include <algorithm>



using namespace std;



//vector<string> M_sort(vector<string>& v)
//{
//	vector<string> s;
//	for (int i = 0; i < v.size(); i++)
//	{
//		s.push_back(v[i]);
//		for (int j = 0; j < v[i].size(); j++)
//		{
//			s[i][j] = (tolower(v[i][j]));
//		}
//	}
//	return s;
//}
//
//
//
//
//void quickSort(vector<string>& arr, int left, int right) {
//	vector<string> s = M_sort(arr);
//	int i = left, j = right;
//	string tmp;
//	string pivot = s[(left + right) / 2];
//
//	/* partition */
//	while (i <= j) {
//		while (s[i] < pivot)
//			i++;
//		while (s[j] > pivot)
//			j--;
//		if (i <= j) {
//			tmp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = tmp;
//			i++;
//			j--;
//		}
//	};
//
//	/* recursion */
//	if (left < j)
//		quickSort(arr, left, j);
//	if (i < right)
//		quickSort(arr, i, right);
//
//}

void low(string& v)
{
	
		for (int j = 0; j < v.size(); j++)
		{
			v[j] = tolower(v[j]);
		}
	
}

bool init(string s1, string s2)
{
	low(s1);
	low(s2);
	if (s1 < s2)
		return true;
	else
		return false;
}

int main()
{
	
	vector<string> v;
	unsigned int N;
	cin >> N;
	if (N == 0)
		return 0;
	else if (N > 1000)
		return 0;
	for (int i = 0; i < N; i++)
	{
		string h;
		cin >> h;
		if ((h.size() > 15) || (h.size() < 1))
			return 0;
		else
			v.push_back(h);
	}
	sort(v.begin(), v.end(), init);
	for (int j = 0; j < v.size(); j++)
	{
		cout << v[j] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

