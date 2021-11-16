#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void	Read_double(const string& path) {
	ifstream input(path);
	if (input) {
		double value;
		while (input >> value) {
			cout << value << endl;
		}
	}
}

int		main() {
	cout << fixed << setprecision(3);
	Read_double("input.txt");
	return 0;
}
