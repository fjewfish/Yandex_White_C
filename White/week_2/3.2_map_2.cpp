//3.2_map.cpp
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void				PrintMap2(const map<string, int>& m) {
	cout << "\nSize_of_map = " << m.size() << "\n";
	for (const auto& item : m) {
		cout << item.first << " : " << item.second << endl;
	}
}

int					main () {
	map<string, int> m = {{"one", 1}, {"two", 2}, {"three",  3}};
	PrintMap2(m);
	m.erase("one");
	PrintMap2(m);

//при обращение создается новая пара с ключом
	vector<string> words = {"one", "two", "one"};
	map<string, int> counters;
	for (const string& word : words) {
		//if (counters.count(word)) {
		//	counters[word] = 1;
		//} else {
		++counters[word];
	}
	PrintMap2(counters);

	words = {"one", "two", "three"};
	map <char, vector<string>> result;
	for (const string& word : words) {
		result[word[0]].push_back(word);
	}
	for (const auto& item : result) {
		cout << item.first << endl;
		for (const string& word : item.second) {
			cout << word << ' ';
		}
		cout << endl;
	}
	return 0;
}
