//simple_operations.cpp
#include <string>
#include <iostream>
using namespace std;

int main () {
	int x = 4;
	int y = 5;
	cout << (x + y) * -1;
	if (x == y){
		cout << "equal";
	} else {
		cout << "not equal";
	}
	return 0;

	string s1 = "abc";
	string s2 = "abc";
	//сравниваются лексекографически
	if (s1 < s2){
		cout << "less";
	} else {
		cout << "not less";
	}
	return 0;
}
