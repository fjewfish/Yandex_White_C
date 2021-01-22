// 2.0_plus_operation.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main () {
	int x = 5;
	x = 6;
	cout << x << '\n';
//full copy
	string s = "hello";
	string t = s;
	t += ", worl";
	cout << s << endl;
	cout << t << endl;

	vector<string> w = {"one", "two", "abc"};
	vector<string> v;
	v = w;
	v[0] = "1";
	cout << w[0] << " " << w[1] << " " << w[2] << endl;
	cout << v[0] << " " << v[1] << " " << v[2] << endl;
	return 0;
}
