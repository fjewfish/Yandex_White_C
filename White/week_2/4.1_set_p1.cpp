//4.1_set_p1.cpp
#include <iostream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

void PrintSet(const set<string>& s) {
	cout << "Size = " << s.size() << endl;
	for (auto x : s) {
		cout << x << endl;
	}
}

int		main () {
	map<string, bool> is_famous_person;
	is_famous_person["Stroustrup"] = true;
	is_famous_person["Ritchie"] = true;

	set<string> famoous_pers;
	famoous_pers.insert("Ritchie");
	famoous_pers.insert("Stroustrup");
	famoous_pers.insert("Ritchie");
	famoous_pers.insert("Stroustrup");
	famoous_pers.insert("DEN");
	PrintSet(famoous_pers);
	famoous_pers.erase("DEN");
	PrintSet(famoous_pers);
	return 0;
}
