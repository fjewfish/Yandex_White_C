#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void ReadAll(const string& path) {
	ifstream input(path);
	if (input) {
		string line;
		while (getline(input, line))
		{
			cout << line << endl;
		}
	}
}

int		main() {
	ifstream input_date("date.txt");
	int year;
	int month;
	int day;
	if (input_date) {
		input_date >> day;
		input_date.ignore(1);
		input_date >> month;
		input_date.ignore(1);
		input_date >> year;
		input_date.ignore(1);
		cout << day << '.' << month << '.' << year << endl;
		cout << "nice!\n";
	} else {
		cout << "error!\n";
	}

	const string path = "output.txt";
//ios::app   add to file
	ofstream output(path, ios::app);
	output << "world" << endl;
	ReadAll(path);
	return 0;
}
⁄€
