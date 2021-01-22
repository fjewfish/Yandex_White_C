//3.0_if.cpp
#include <iostream>
using namespace std;

int main () {
	int a, b;
	cin >> a >> b;
	if (a == b)
		cout << "equal\n";
	else
		cout << "not equal\n";

	if (a > 0)
		cout << "positive";
	else
		cout << "negative";
	return 0;
}
