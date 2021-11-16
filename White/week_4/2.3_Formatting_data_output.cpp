#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void Print_value(const vector<string>& names, const vector<double>& values, int width) {
	for (const auto& n : names) {
		cout << setw(width) << n << ' ';
	}
	cout << endl;
	cout << fixed << setprecision(2);
	for (const auto& n : values) {
		cout << setw(width) << n << ' ';
	}
}

int		main(){
	vector<string> names = {"a", "b", "c"};
	vector<double> values = {5, 0.01, 0.00004};
	cout << setfill('.');
	cout << left;
	Print_value(names, values, 10);
	return 0;
}
