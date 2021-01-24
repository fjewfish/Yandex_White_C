//1.1_introduction_to_functions.cpp
#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool Contains (vector<string> words, string w) {
	for (auto s : words) {
		if (s == w)
			return true;
	}
	return false;
}

int Sum (int x, int y) {
	return x + y;
}

int main () {
	int x, y;
	cin >> x >> y;
	cout << Sum (x, y) << endl;

	cout << Contains({"air", "water"}, "water") << endl;
	return 0;
}
