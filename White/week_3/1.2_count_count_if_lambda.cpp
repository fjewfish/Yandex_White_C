//1.2_count_count_if_lambda.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

void Print(const vector<int>& v, const string& title) {
	cout << title << ": ";
	for (auto i : v) {
		cout << i << ' ';
	}
	cout << endl;
}

bool Gt2(int x) {
	if (x > 2) {
		return true;
	}
	return false;
}

int		main () {
	vector<int> v {
		3, 2, 5, 4, 1, 2, 1
	};
	Print(v, "init");
	int cnt = 0;
	for (const auto& i : v) {
		if (i == 2)
			++cnt;
	}
	cout << cnt << endl;
	cout << count(begin(v), end(v), 2) << endl;
	cout << count_if(begin(v), end(v), Gt2) << endl;
	cout << "lalmbda    " << count_if(begin(v), end(v), [](int x) {
		if (x > 2) {
			return true;
		}
		return false;
	}) << endl;

	int  thr = 0;
	cin >> thr;
	cout << "thr    " << count_if(begin(v), end(v), [thr](int x) {
		if (x > thr) {
			return true;
		}
		return false;
	}) << endl;
	return 0;
}
