#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>
#include <map>
#include <iomanip>
#include <sstream>

using namespace std;



bool CheckData(string& date) {
	stringstream str(date);
	int a, b, c;
	char def1, def2;
	return str >> a >> def1 >> b >> def2 >> c && str.peek() == EOF && def1 == '-' && def2 == '-';

}

class Date {
public:
	Date(const string &stream) {
		istringstream input(stream);
		char c, d;
		int new_year, new_month, new_day;
		input >> new_year >> c >> new_month >> d >> new_day;
		string year = to_string(new_year);
		string month = to_string(new_month);
		string day = to_string(new_day);
		string ful = year + c + month + d + day;
		if (!CheckData(ful))
		{
			cout << "Wrong date format: ";
			throw invalid_argument(stream);
		}
		if (new_month > 12 || new_month < 1)
		{
			cout << "Month value is invalid: ";
			throw invalid_argument(to_string(new_month));
		}
		if (new_day > 31 || new_day < 1)
		{
			cout << "Day value is invalid: ";
			throw invalid_argument(to_string(new_day));
		}
		year = new_year;
		month = new_month;
		day = new_day;
	}
	int year;
	int month;
	int day;
	int GetYear() const
	{
		return year;
	}
	int GetMonth() const
	{
		return month;
	}
	int GetDay() const
	{
		return day;
	}
};



//Date vvod(const string& s)
//{
//	stringstream stream(s);
//	Date date;
//	stream >> date.year;
//	if (stream.peek() != '-')
//		throw exception();
//	stream.ignore(1);
//	stream >> date.month;
//	if (stream.peek() != '-')
//		throw exception();
//	stream.ignore(1);
//	stream >> date.day;
//	return date;
//}

bool operator<(const Date& l, const Date& r)
{
	if (l.year < r.year)
		return true;
	else if (l.year == r.year)
	{
		if (l.month < r.month)
			return true;
		else if (l.month == r.month)
		{
			if (l.day < r.day)
				return true;
			else
				return false;

		}
		else if (l.month > r.month)
			return false;
	}
	else if (l.year > r.year)
		return false;
}

ostream& operator<<(ostream& stream, const Date& date)
{
	stream << setfill('0');
	stream << setw(4) << date.year << '-' << setw(2) << date.month << '-' << setw(2) << date.day;
	return stream;
}

//istream& operator>>(istream& stream,  Date& date)
//{
//	char c, b;
//	stream >> date.year >> c >> date.month >> b >> date.day;
//	if ((c == '-') && (b == '-'))
//	{
//		if ((date.month > 12) || (date.month < 1))
//		{
//			stringstream ss;
//			ss << "Month value is invalid: " << date.month;
//			throw runtime_error(ss.str());
//		}
//		else if ((date.day < 1) || (date.day > 31))
//		{
//			stringstream ss;
//			ss << "Day value is invalid: " << date.day;
//			throw runtime_error(ss.str());
//		}
//	}
//	else 
//	{
//		stringstream ss;
//		ss << "Wrong date format: " << date;
//		throw runtime_error(ss.str());
//	}
//	return stream;
//}

class Database {
public:
	map<Date, vector<string>> dates;
	void AddEvent(const Date& date, const string& event)
	{
		int c = 0;
		for (int i = 0; i < dates[date].size(); i++)
		{
			if (dates[date][i] == event)
			{
				c++;
			}
		}
		if (c == 0)
		{
			dates[date].push_back(event);
			sort(dates[date].begin(), dates[date].end());
		}
	}
	bool DeleteEvent(const Date& date, const string& event)
	{
		int c = 0;
		for (int i = 0; i < dates[date].size(); i++)
		{
			if (dates[date][i] == event)
			{
				dates[date].erase(dates[date].begin() + i);
				c++;
			}
		}
		if (c == 0)
			return false;
		else
			return true;
	}
	int  DeleteDate(const Date& date)
	{
		int n = dates[date].size();
		dates[date].clear();
		return n;
	}

	void Find(const Date& date) /*const*/
	{
		for (int i = 0; i < dates[date].size(); i++)
		{
			cout << dates[date][i] << endl;
		}
	}

	void Print() /*const*/
	{
		for (auto i = dates.begin(); i != dates.end(); ++i)
		{
			for (int j = 0; j < i->second.size(); j++)
				cout << i->first << " " << i->second[j] << endl;
		}
	}
};

int main() {
	Database db;

	string com;

	while (getline(cin, com)) {
		/*while (com.empty())
			getline(cin, com);*/
		istringstream input(com);
		string request;
		input >> request;
		if (request == "Add")
		{
			string data;
			string event;
			input >> data >> event;
			
			try {
				Date date(data);
				db.AddEvent(date, event);
			}
			catch (exception& ex) {
				cout << ex.what() << endl;
				break;
			}
		}
		else if (request == "Del")
		{
			string event, data;
			input >> data >> event;
			
			
			try {
				Date date(data);
				if (event.length() != 0)
				{
					bool b = db.DeleteEvent(date, event);
					if (b == true)
						cout << "Deleted successfully" << endl;
					else
						cout << "Event not found" << endl;
				}
				else
				{
					int n = db.DeleteDate(date);
					string s = "Deleted " + to_string(n) + " events";
					cout << s << endl;
				}
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl;
				break;
			}
			
		}
		else if (request == "Find")
		{
			string data;
			input >> data;
			try {
				Date date(data);
				db.Find(date);
			}
			catch (exception& ex) {
				cout << ex.what() << endl;
				break;
			}
			
		}
		else if (request == "Print")
		{
			db.Print();
		}
		else if (com.empty() == false){
			
				cout << "Unknown command: " << request << endl;
		}

	}
	system("pause");

	return 0;
}