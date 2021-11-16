//1.2_function_parameters.cpp
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void	PrintWords(vector<string> words) {
	for (auto w : words) {
		cout << w << " ";
	}
	cout << endl;
}

void	ChangeInt(int x) {
	x = 42;
}

int		main () {
	PrintWords({"air", "fire", "water"});

	int a = 5;
//only copy
	ChangeInt(a);
	cout << a;
	return 0;
}
