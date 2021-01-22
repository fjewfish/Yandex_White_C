//3.2_for.cpp
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

void	main2();

int main () {
	vector<int> a = {3, 3, 4, 10};
	int sum = 0;

	for (auto i : a) {
		sum += i;
	}
	cout << sum << endl;

	map<string, int> b = {{"a", 1}, {"b", 2}};
	sum = 0;
	string concat;
	for (auto i : b) {
		concat += i.first;
		sum += i.second;
	}
	cout << concat << endl << sum << endl;
	string str = "asdfafdjkla";
	int i = 0;
	for (auto c : str) {
		if (c == 'a') {
			cout << i << endl;
		}
		i++;
	}
	for (int j = 0; j < str.size(); ++i) {
		if (str[j] == 'a') {
			cout << j << endl;
		}
		j++;
	}
	main2();
	return 0;
}
 void main2() {
	 int i = 0;
	 string str = "safdasdflkjasdfasd";
	 for (int j = 0; j < str.size(); ++i) {
		if (str[j] == 'a') {
			cout << j << endl;
			break;
		}
		j++;
	}
 }
