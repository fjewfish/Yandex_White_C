//3.1_map.cpp
#include <string>
#include <iostream>
#include <map>
using namespace std;

void				PrintMap(const map<int, string>& m) {
	cout << "Size_of_map = " << m.size() << "\n";
	for (auto item : m) {
		cout << item.first << " : " << item.second << endl;
	}
	cout << endl;
}

void				PrintMap2(const map<string, int>& m) {
	cout << "Size_of_map = " << m.size() << "\n";
	for (auto item : m) {
		cout << item.first << " : " << item.second << endl;
	}
	cout << endl;
}

map<string, int>	BuildReverseMap(const map<int, string>& events) {
	map<string, int> result;
	for (auto item : events) {
		result[item.second] = item.first;
	}
	return result;
}

int					main () {
	map<int, string> events;
	events[1950] = "Bjarne Stroustrup a birth";
	events[1941] = "Dennis Ritchie a birth";
	events[1970] = "UNIX epoch start";
//auto sort (map)
	PrintMap(events);

	cout << events[1950] << endl;

	events.erase(1970);
	PrintMap(events);

	PrintMap2(BuildReverseMap(events));

	return 0;
}
