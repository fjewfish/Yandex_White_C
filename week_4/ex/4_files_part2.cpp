#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int		main() {
	ifstream file("input.txt");
	ofstream output("output.txt");
	if (file) {
		string line;
		while (getline(file, line)) {
			output << line << endl;
		}
	}
	return 0;
}
