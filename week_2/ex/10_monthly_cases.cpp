//10_monthly_cases.cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const vector<int> MONTH_LENGTHS =
  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int		main () {
	int q, days = 0;
	cin >> q;
	vector<vector<string>> this_month(MONTH_LENGTHS[days]);
	for (int j = 0; j < q; j++) {
		string command;
		cin >> command;
		int i;
		if (command == "ADD") {
			string s;
			cin >> i >> s;
			this_month[i - 1].push_back(s);
		} else if (command == "DUMP") {
			cin >> i;
			cout << this_month[i - 1].size() << ' ';
			for (string s : this_month[i - 1]) {
				cout << s << ' ';
			}
			cout << endl;
		} else if (command == "NEXT") {
			int previous = days;
			days++;
			if (days == 12)
				days = 0;
			if (MONTH_LENGTHS[days] < MONTH_LENGTHS[previous]) {
				for (int i = MONTH_LENGTHS[days]; i < MONTH_LENGTHS[previous]; i++) {
					//for (auto s : this_month[i]) {
					//	this_month[MONTH_LENGTHS[days] - 1].push_back(s);
					//}

					//v1.insert(end(v1), begin(v2), end(v2));
					this_month[MONTH_LENGTHS[days] - 1].insert(end(this_month[MONTH_LENGTHS[days] - 1]),
						begin(this_month[i]),
							end(this_month[i]));
				}
			}
			this_month.resize(MONTH_LENGTHS[days]);
		}
	}
	return 0;
}
