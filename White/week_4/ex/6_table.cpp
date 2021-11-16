#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int		main() {
	ifstream input("input.txt");
	if (input) {
		int rows = 0, columns = 0;
		input >> rows;
		input >> columns;
		int const i = columns;
		while (rows) {
			while (columns) {
				int number;
				input >> number;
				cout << setw(10) << number;
				input.ignore(1);
				columns--;
			}
			columns = i;
			rows--;
			if (rows)
				cout << endl;
		}
	}
	return 0;
}
