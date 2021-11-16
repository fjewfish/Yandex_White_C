#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct LectureTitle
{
	string specialization;
	string week;
};


struct  Lecture
{
	LectureTitle full_title;
	string title;
	string author;
	int duration;
};

void PrintLecture(const Lecture& lecture) {
	cout <<
		"Title: " << lecture.title <<
		", duration: " << lecture.duration <<
		", author: " << lecture.author << endl;
}

void PrintCoutse(const vector<Lecture>& lectures) {
	for (const Lecture& lecture : lectures) {
		PrintLecture(lecture);
	}
}

int main() {
	Lecture lecture1;
	lecture1.title = "OOP";
	lecture1.duration = 5400;
	lecture1.author = "Anton";
	Lecture lecture2 = {"OOP2", "Dima", 3400};
	PrintLecture(lecture1);
	PrintLecture(lecture2);
	return 0;
}
