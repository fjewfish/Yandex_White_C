//3.3_map_C++17.cpp
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int					main () {
	map<string, int> m = {{"one", 1}, {"two", 2}};
	//for (const auto& item : m) {
	//	item.first, item.second;
	//}
	for (const auto& [key, value] : m) {
		key, value;
	}
	return 0;
}
