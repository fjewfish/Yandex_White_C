//2.1_vector_1.cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void	PrintVector(const vector<string>& v) {
	cout << endl;
	for (string s : v) {
		cout << s << endl;
	}
}

int		main () {
	int n;
	cin >> n;
	vector<string> v(n);
	for (string& s : v) {
		cin >> s;
	}
	PrintVector(v);
	vector<string> v2;
	int i = 0;
	while (i < n) {
		string s;
		cin >> s;
		v2.push_back(s);
		i++;
	}
	PrintVector(v);
	return 0;
}
