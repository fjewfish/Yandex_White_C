//2.1_vector_1.cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void	PrintVector(const vector<int>& v) {
	cout << endl;
	for (auto s : v) {
		cout << s << endl;
	}
}

void	PrintVector_2(const vector<bool>& v) {
	cout << endl;
	for (auto s : v) {
		cout << s << endl;
	}
}

int		main () {
	vector<int> days_in_months = {31, 28, 31};
	PrintVector(days_in_months);

	vector<bool> is_holiday(28, false);
	is_holiday[22] = true;
	PrintVector_2(is_holiday);
	//save data
	//is_holiday.resize(31);
	is_holiday.assign(31, false);
	PrintVector_2(is_holiday);
	is_holiday.clear();
	return 0;
}
