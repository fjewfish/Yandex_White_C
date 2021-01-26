//17_synonyms.cpp
#include <iostream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int				main () {
	int q;
	cin >> q;
	map<string, set<string>> synonyms;

	for (int i = 0; i < q; i++) {
		string command;
		cin >> command;
		if (command == "ADD") {
			string word_1, word_2;
			cin >> word_1 >> word_2;
			synonyms[word_1].insert(word_2);
			synonyms[word_2].insert(word_1);

		} else if (command == "COUNT") {
			string word;
			cin >> word;
			cout << synonyms[word].size() << endl;
		} else if (command == "CHECK") {
			string word_1, word_2;
			cin >> word_1 >> word_2;
			if (synonyms[word_1].count(word_2))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}
