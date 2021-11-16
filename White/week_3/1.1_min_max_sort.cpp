//1.1_min_max_sort.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

int MIN(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int MAX(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

void Print(const vector<int>& v, const string& title) {
	cout << title << ": ";
	for (const auto& i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int		main () {
	cout << MIN(2, 3) << endl;
	cout << MAX(2, 3) << endl;

	cout << min(2, 3) << endl;
	cout << max(2, 3) << endl;

	string s1 = "abc";
	string s2 = "bca";
	cout << min(s1, s2) << endl;

	vector<int> v = {31, 28, 30, 1, 45};
	Print(v, "init");
	sort(begin(v), end(v));
	Print(v, "init");
	return 0;
}
