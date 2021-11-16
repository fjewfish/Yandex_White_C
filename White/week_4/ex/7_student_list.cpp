#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
	string	fist_name;
	string	last_name;
	int		day;
	int		month;
	int		year;

};

int		main() {
	vector<Student>	students;
	int				quantity = 0;
	int				requests = 0;

	cin >> quantity;
	while (quantity) {
		Student	student;

		cin >> student.fist_name >> student.last_name >> student.day >> student.month >> student.year;
		students.push_back(student);
		quantity--;
	}
	cin >> requests;
	while (requests) {
		string	request;
		int		number;

		cin >> request >> number;
		number--;
		if (request == "name") {
			cout << students[number].fist_name << " " << students[number].last_name << endl;
		}
		else if (request == "date") {
			cout << students[number].day << "." << students[number].month << "." << students[number].year << endl;
		}
		else {
			cout << "bad request" << endl;
		}
		requests--;
	}
	return 0;
}
