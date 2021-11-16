//zero overhead principle
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void PrintInt() {
	int x;
	cout << x << endl;
}

void PrintDouble() {
	double pi = 3.14;
	cout << pi << endl;
}

void PrintParity(int x) {
	string patity = (x % 2 == 0) ? "even" : "odd";
	cout << x << " is " << patity << endl;
}

string GetPositivity(int x) {
	if (x > 0) {
		return "positive";
	} else if (x < 0) {
		return "negative";
	} else if (x == 0) {
		return "zero";
	}
	return 0;
}

void PrintPossitivity (int x) {
	string positivity = GetPositivity(x);
	cout << x << " is " << positivity << endl;
}

string Positivity(int x) {
    return x > 0 ? "positive"
                 : (x == 0 ? "zero" : "negative");
}

int main() {
	PrintInt();
	PrintDouble();
	PrintInt();
	cout << endl;
	PrintParity(5);
	PrintParity(10);
	PrintPossitivity(5);
	PrintPossitivity(0);
	PrintPossitivity(-5);
	cout << Positivity(5) << endl;
	cout << Positivity(-5) << endl;
	cout << Positivity(0) << endl;
	return 0;
}
