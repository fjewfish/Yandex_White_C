//3.3_map_C++17.cpp
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<char, int> BuildCharCounters(const string& word) {
  map<char, int> counters;
  for (char c : word) {
    ++counters[c];
  }
  return counters;
}

int					main () {
	int n;
	cin >> n;
		for (int j = 0; j < n; j++) {
			string word_1, word_2;
			cin >> word_1 >> word_2;
			if (BuildCharCounters(word_1) == BuildCharCounters(word_2))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	return 0;
}
