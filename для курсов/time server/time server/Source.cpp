#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
	
}

class TimeServer {
public:
	string GetCurrentTime() {
		try 
		{
			string s = AskTimeServer();
			LastFetchedTime = s;
			return LastFetchedTime;
		}
		catch (system_error& e)
		{
			return LastFetchedTime;
		}
	}

private:
	string LastFetchedTime = "00:00:00";
};

int main() {
	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	}
	catch (exception& e) {
		cout << "Exception got: " << e.what() << endl;
	}
	system("pause");
	return 0;
}
