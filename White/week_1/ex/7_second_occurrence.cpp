//7_second_occurrence.cpp
#include <string>
#include <iostream>
using namespace std;

//-1 if only 1 'f'
//-2 if no 'f'
int main () {
	string str;
	int sum = 0;
	cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'f')
			sum++;
		if (sum == 2) {
			cout << i;
			break;
		}
	}
	if (sum == 0)
		cout << -2;
	else if (sum == 1)
		cout << -1;
	return 0;
}
