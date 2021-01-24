//2.2_if_else.cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main () {
	int a = 5;
	int b = 7;
	if (a < b) {
		cout << "a is less than b\n";
	}
	string c = "fire";
	string d = "water";
//сравниваются лексекографически
	if (c < d) {
		cout << "c is less than d\n";
	}
	vector<string> e = {"fire", "water"};
	vector<string> f = {"fire", "fog"};
	if (e == f) {
		cout << "equal\n";
	} else {
		cout << "not equal\n";
	}
	map<int, string> g;
	g[1] = "one";
	map<int, string> h;
	if (g == h) {
		cout << "equal\n";
	} else {
		cout << "not equal\n";
	}

	c = "abc";
	if (!c.empty() && c < "zzz") {
		cout << c << endl;
	}
	return 0;
}
