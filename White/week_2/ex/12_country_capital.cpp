//12_country_capital.cpp
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int					main () {
	int n;
	cin >> n;
	map<string, string> handbook;
	for (int j = 0; j < n; j++) {
		string command;
		cin >> command;
		string country, capital;
		string old_country, new_country;
		if (command == "CHANGE_CAPITAL") {
			cin >> country >> capital;
			if (!handbook.count(country)) {
				cout << "Introduce new country " << country << " with capital " << capital << endl;
			} else if (handbook[country] == capital) {
				cout << "Country " << country << " hasn't changed its capital" << endl;
			} else {
				cout << "Country " << country << " has changed its capital from " << handbook[country] << " to " << capital << endl;
			}
			handbook[country] = capital;

		} else if (command == "RENAME") {
			cin >> old_country >> new_country;
			if (old_country == new_country || !handbook.count(old_country) || handbook.count(new_country)) {
				cout << "Incorrect rename, skip" << endl;
				if (!handbook.count(old_country))
					handbook.erase(old_country);
			} else {
				cout << "Country " << old_country << " with capital " << handbook[old_country] << " has been renamed to " << new_country << endl;
				handbook[new_country] = handbook[old_country];
				handbook.erase(old_country);
			}

		} else if (command == "ABOUT") {
			cin >> country;
			if (!handbook.count(country)) {
				cout << "Country " << country << " doesn't exist" << endl;
				handbook.erase(country);
			} else {
				cout << "Country " << country << " has capital " << handbook[country] << endl;
			}

		} else if (command == "DUMP") {
			if (!handbook.size()) {
				cout << "There are no countries in the world" << endl;
			} else {
				for (const auto& i : handbook) {
					cout << i.first << '/' << i.second << ' ';
				}
				cout << endl;
			}
		}
	}
	return 0;
}

