//1.3_modifying_range-based_for.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

void Print(const vector<int>& v, const string& title) {
	cout << title << ": ";
	for (const auto& i : v) {
		cout << i << ' ';
	}
	cout << endl;
}

int		main () {
	vector<int> v {
		3, 2, 5, 4, 1, 2, 1
	};
	Print(v, "init");
	//for (int i = 0; i < v.size(); ++i) {
	//	++v[i];
	//}
	for (auto& i : v) {
		++i;
	}
	Print(v, "inc ");
	return 0;
}
