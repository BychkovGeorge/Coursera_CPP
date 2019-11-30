#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		fio_name[year] = first_name;
	}

	void ChangeLastName(int year, const string& last_name) {
		fio_surname[year] = last_name;
	}

	string GetFullName(int year) {
		string  result_name = "";
		string  result_surname = "";


		for (auto item : fio_name)
		{
			if (item.first <= year) { result_name = item.second; }
		}
		for (auto item : fio_surname)
		{
			if (item.first <= year) { result_surname = item.second; }
		}

		//no name
		if ((result_name.size() == 0) && (result_surname.size() != 0)) {
			return (result_surname + " with unknown first name");
		}
		//no last_name                                                                    
		else if ((result_name.size() != 0) && (result_surname.size() == 0)) {
			return (result_name + " with unknown last name");
		}
		//all OK                                                                                                                                            
		else if ((result_name.size() != 0) && (result_surname.size() != 0)) {
			return (result_name + " " + result_surname);
		}
		else
			return "Incognito";


	}

	string GetFullNameWithHistory(int year) {
		vector<string>  result_name;
		vector<string>  result_surname;


		for (auto item : fio_name)
		{
			if (item.first <= year)
			{
				result_name.push_back(item.second);
			}
		}
		for (auto item : fio_surname)
		{
			if (item.first <= year) 
			{
				result_surname.push_back(item.second); 
			}
		}
		if (result_name.size() != 0)
		{
			for (int i = 0; i < result_name.size() - 1; i++)
			{
				if (result_name[i] == result_name[i + 1])
				{
					result_name.erase(result_name.begin() + i);
					--i;
				}
			}
		}

		if (result_surname.size() != 0)
		{
			for (int i = 0; i < result_surname.size() - 1; i++)
			{
				if (result_surname[i] == result_surname[i + 1])
				{
					result_surname.erase(result_surname.begin() + i);
					--i;
				}
			}
		}

		//no name
		if ((result_name.size() == 0) && (result_surname.size() != 0))
		{
			string res;
			res = result_surname[result_surname.size() - 1];
			if (result_surname.size() > 1)
			{
				res += " (";
				for (int i = result_surname.size() - 2; i > -1; i--)
				{
					if (i == 0)
						res += result_surname[i];
					else
						res += result_surname[i] + ", ";
				}
				res += ")";
			}
			return (res + " with unknown first name");
		}
		//no last_name                                                                    
		else if ((result_name.size() != 0) && (result_surname.size() == 0))
		{
			string res;
			res = result_name[result_name.size() - 1];
			if (result_name.size() > 1)
			{
				res += " (";
				for (int i = result_name.size() - 2; i > -1; i--)
				{
					if (i == 0)
						res += result_name[i];
					else
						res += result_name[i] + ", ";
				}
				res += ")";
			}
			return (res + " with unknown last name");
		}
		//all OK                                                                                                                                            
		else if ((result_name.size() != 0) && (result_surname.size() != 0))
		{
			string res;
			res = result_name[result_name.size() - 1];
			if (result_name.size() > 1)
			{
				res += " (";
				for (int i = result_name.size() - 2; i > -1; i--)
				{
					if (i == 0)
						res += result_name[i];
					else
						res += result_name[i] + ", ";
				}
				res += ")";
			}
			res += " " + result_surname[result_surname.size() - 1];
			if (result_surname.size() > 1)
			{
				res += " (";
				for (int i = result_surname.size() - 2; i > -1; i--)
				{
					if (i == 0)
						res += result_surname[i];
					else
						res += result_surname[i] + ", ";
				}
				res += ")";
			}
			return res;
		}
		else
			return "Incognito";
	}

private:
	map <int, string> fio_name;
	map <int, string> fio_surname;
};


int main() {

	
	system("pause");
	return 0;
}