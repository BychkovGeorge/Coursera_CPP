#include <iostream>
#include <string>
#include <vector>


using namespace std;

struct Specialization {
	
	string name;
	
	explicit Specialization(string m) {
		name = m;
	}
};

struct Course {
	
	string name;

	explicit Course(string m) {
		name = m;
	}
};

struct Week {
	
	string name;
	
	explicit Week(string m) {
		name = m;
	}
};

struct LectureTitle {
	
	string specialization;
	string course;
	string week;

	
	LectureTitle(Specialization s, Course c, Week w) {
		specialization = s.name;
		course = c.name;
		week = w.name;
	}
};

int main()
{
	

	return 0;
}