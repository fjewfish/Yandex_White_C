//6_even_numbers.cpp
#include <iostream>
using namespace std;

//A и B (A <= B, A >= 1, B <= 30000).
int main () {
	int a, b;
	cin >> a >> b;
	if (a <= b && a >= 1 && b <= 30000) {
		if (a % 2 != 0)
			a++;
		while (a <= b) {
			cout << a << ' ';
			a += 2;
		}
	}
	return 0;
}
