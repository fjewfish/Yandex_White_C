#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int		main() {
	ifstream input("hello.txt");
	string line;
	// also you can ese bool value:
	// if (input) {}
	if (input.is_open()) {
		while (getline(input, line)) {
		cout << line << endl;
		}
		cout << "nice!\n";
	} else {
		cout << "error!\n";
	}
	ifstream input_date("date.txt");
	string year;
	string month;
	string day;
	if (input_date) {
		getline(input_date, day, '-');
		getline(input_date, month, '-');
		getline(input_date, year, '\n');
		cout << day << '.' << month << '.' << year << endl;
		cout << "nice!\n";
	} else {
		cout << "error!\n";
	}
	return 0;
}
