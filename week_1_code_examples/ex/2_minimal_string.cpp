//minimal_string.cpp
#include <string>
#include <iostream>
using namespace std;

int main () {
	string a, b, c;
	cin >> a >> b >> c;
	if (a <= b && a <= c) {
		cout << a;
	} else if (b <= c) {
		cout << b;
	} else {
		cout << c;
	}
	return 0;
}
