//15_unique_str_count.cpp
#include <iostream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int		main () {
	int n;
	cin >> n;
	set<string> unique_str;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		unique_str.insert(str);
	}
	cout << unique_str.size() << endl;
	return 0;
}
