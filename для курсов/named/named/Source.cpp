//#include <iostream>
//#include <string>
//#include <map>
//#include <ctime>
//
//using namespace std;
//
//class name {
//public:
//	
//	bool is_name = false;
//	string Name;
//};
//
//class surname {
//public:
//
//	bool is_family = false;
//	string family;
//};
//
//class Person {
//public:
//
//	/*Person()
//	{
//		for (int i = 0; i < 10000; i++)
//		{
//			info[i].is_name = false;
//			info[i].is_family = false;
//		}
//	}*/
//	void ChangeFirstName(int year, const string& first_name)
//	{
//		
//		if (year < info.begin()->first)
//		{
//			for (int i = year; i < info.begin()->first; i++)
//			{
//				info[i].Name = first_name;
//				info[i].is_name = true;
//			}
//		}
//		else if ((year < info.end()->first) && (year > info.begin()->first))
//		{
//			string s = info[year].Name;
//			int i = year;
//			while (s == info[i].Name)
//			{
//				i++;
//			}
//			for (int j = year; j < i; j++)
//			{
//				info[i].Name = first_name;
//				info[i].is_name = true;
//			}
//		}
//		else if (info.size() == 0)
//		{
//			for (int i = year; i < 10000; i++)
//			{
//				info[i].Name = first_name;
//				info[i].is_name = true;
//			}
//		}
//		else
//		{
//			for (int i = year; i < 10000; i++)
//			{
//				info[i].Name = first_name;
//				info[i].is_name = true;
//			}
//		}
//	}
//
//	void ChangeLastName(int year, const string& last_name)
//	{
//		if ((info1.size() == 0) || (year > info1.end()->first))
//		{
//			for (int i = year; i < 10000; i++)
//			{
//				info1[i].family = last_name;
//				info1[i].is_family = true;
//			}
//		}
//		else if (year < info1.begin()->first)
//		{
//			for (int i = year; i < info1.begin()->first; i++)
//			{
//				info1[i].family = last_name;
//				info1[i].is_family = true;
//			}
//		}
//		else if ((year < info1.end()->first) && (year > info1.begin()->first))
//		{
//			string s = info1[year].family;
//			int i = year;
//			while (s == info1[i].family)
//			{
//				i++;
//			}
//			for (int j = year; j < i; j++)
//			{
//				info1[i].family = last_name;
//				info1[i].is_family = true;
//			}
//		}
//	}
//
//	string GetFullName(int year)
//	{
//		
//		
//		if ((info[year].is_name == false) && (info1[year].is_family == false))
//			return "Incognito";
//		else if ((info[year].is_name == true) && (info1[year].is_family == false))
//			return info[year].Name + " with unknown last name"; 
//		else if ((info[year].is_name == false) && (info1[year].is_family == true))
//			return info1[year].family + " with unknown first name";
//		else if ((info[year].is_name == true) && (info1[year].is_family == true))
//			return info[year].Name + " " + info1[year].family;
//	}
//private:
//	map<int, name> info;
//	map<int, surname> info1;
//};
//
//
//int main() {
//	Person person;
//
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeLastName(1967, "Sergeeva");
//	for (int year : {1900, 1965, 1990}) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	person.ChangeFirstName(1970, "Appolinaria");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	person.ChangeLastName(1968, "Volkova");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	
//
//	system("pause");
//	return 0;
//}

#include <map>
#include <string>
#include <iostream>

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

private:
	map <int, string> fio_name;
	map <int, string> fio_surname;
};


int main() {

	
	return 0;
}