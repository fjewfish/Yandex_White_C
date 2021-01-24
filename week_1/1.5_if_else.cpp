// 5_if_else.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main () {
	int x = 5;
	int y = 5;
	if (x ==y) {
		cout << "qual\n";
	}

	int n = 5;
	int sum = 0;
	for (int i = 1; i <=n; ++i) {
		sum += i;
	}
	cout << sum << '\n';
	sum = 0;
	int i = 0;
	while (i <= n) {
		sum += i;
		i += 1;
	}
	cout << sum << '\n';
	return 0;
}
