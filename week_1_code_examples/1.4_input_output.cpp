//4_input_output.cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//cin -> console input
//cout -> console output
int main () {
	int x = 4;
	string y = "hello";
	cout << x << ' ' << y << '\n';

	vector<int> d = {1, 4};
//input
	int d1, d2;
	cin >> d1 >> d2;
	cout << d1 + d2 << '\n';
//hello program
	string name;
	cin >> name;
	cout << "Hello " << name << '\n';
//*Строки считываются до первого пробельного символа
	return 0;
}
