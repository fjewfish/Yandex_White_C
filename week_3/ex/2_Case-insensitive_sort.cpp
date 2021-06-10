//2_Case-insensitive_sort.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <cctype>
using namespace std;

bool	lexi_compare (string str1, string str2) {
	int i = 0;
	while (str1[i] && str2[i]) {
		if (tolower(str1[i]) < tolower(str2[i]))
			return true;
		++i;
	}
	if (!str1[i] && str2[i] && str1[i - 1] <= str2[i - 1])
		return true;
	return false;
}

int		main () {
	//int n;
	//cin >> n;
	//vector<string> str(n);
	//for (auto& i : str) {
	//	cin >> i;
	//};
	//sort(begin(str), end(str), lexi_compare);
	//for (const auto& i : str) {
	//	cout << i << " ";
	//};


	int n;
	cin >> n;
	vector<string> str(n);
	for (auto& i : str) {
		cin >> i;
	};
	sort(begin(str), end(str), [](const string& l, const string& r) {
		return lexicographical_compare(begin(l), end(l),begin(r), end(r),
		[](char cl, char cr) { return tolower(cl) < tolower(cr); });
	});
	for (const auto& i : str) {
		cout << i << " ";
	};


	//vector<string> str;
	//str.push_back("AsorGudhIH4Jmvr");
	//str.push_back("05RpkV4v0JnsGv3");
	//sort(begin(str), end(str), lexi_compare);
	//for (const auto& i : str) {
	//	cout << i << " ";
	//}
	//str.clear();
	//cout << endl;

	//str.push_back("a");
	//str.push_back("C");
	//str.push_back("b");
	//str.push_back("a");
	//str.push_back("C");
	//str.push_back("b");
	//sort(begin(str), end(str), lexi_compare);
	//for (const auto& i : str) {
	//	cout << i << " ";
	//}
	//str.clear();
	//cout << endl;

	//str.push_back("ab");
	//str.push_back("a");
	//str.push_back("abb");
	//str.push_back("a");
	//str.push_back("az");
	//sort(begin(str), end(str), lexi_compare);
	//for (const auto& i : str) {
	//	cout << i << " ";
	//}
	//str.clear();
	//cout << endl;
	return 0;
}
