#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(string s) {
	for (int i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}
vector <string> PalindromFilter(vector <string> words, int minLenght) {
	vector <string> result;
	for (auto a : words) {
		if (a.size() >= minLenght && IsPalindrom(a) == true) {

			result.push_back(a);
		}
	}
	return result;
}


int main() {

	vector <string> words = { "abacaba" , "aba" };
	int minLenght;
	vector <string> output;

	cin >> minLenght;



	output = PalindromFilter(words, minLenght);

	for (auto b : output) {
		cout << b;
	}
	return 0;
}