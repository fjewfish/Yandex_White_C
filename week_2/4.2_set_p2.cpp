//4.2_set_p2.cpp
#include <iostream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

void PrintSet(const set<string>& s) {
	cout << "Size = " << s.size() << endl;
	for (auto x : s) {
		cout << x << endl;
	}
}

int		main () {
	set<string> month_names = {"January", "March", "Feb", "Feb"};
	set<string> month_names_2 = {"January", "March", "Feb"};
	PrintSet(month_names);
	cout << (month_names == month_names_2) << endl;
	cout << month_names.count("Feb") << endl;

	vector<string> v = {"a", "b", "a"};
	set<string> s(begin(v), end(v));
	PrintSet(s);
	return 0;
}
