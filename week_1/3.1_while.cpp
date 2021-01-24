//3.1_while.cpp
#include <iostream>
using namespace std;

int main () {
	int n;

	cin >> n;
//сумма от 1 до n = (n * (n + 1))\2
	int sum = 0;
	if (n >= 1) {
		while (n > 0) {
			sum += n;
			--n;
		}
		cout << sum << endl;
	}
	else
		cout << "enter positive number\n";

	int a = 5;
	int b;
	do {
		cout << "Guess the number: ";
		cin >> b;
	} while (a != b);
	cout << "GJ\n";
	return 0;
}
