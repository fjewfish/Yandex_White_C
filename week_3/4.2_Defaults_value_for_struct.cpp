#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct  Lecture
{
	string title = "C++";
	string author = "Dnis";
	int duration = 0;
};

void PrintLecture(const Lecture& lecture) {
	cout <<
		"Title: " << lecture.title <<
		", duration: " << lecture.duration <<
		", author: " << lecture.author << endl;
}

int main() {
	Lecture lecture1;
	PrintLecture(lecture1);
	Lecture lecture2 = {"OOP"};
	PrintLecture(lecture2);
	return 0;
}
