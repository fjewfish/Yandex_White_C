//1.5_const_pretection.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//const модификатор типа запрещающий изменения
int		main () {
	const int x = 5;
	cout << x << endl;

	string s = "asdjlkf";
	cout << s.size() << ' ' << s << endl;

	const vector<string> w = {"hello"};
	cout << w[0];
	return 0;
}
