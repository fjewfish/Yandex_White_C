#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int		main() {
	ifstream file("input.txt");
	if (file) {
		string line;
		while (getline(file, line)) {
			cout << line << endl;
		}
	}
	return 0;
}
