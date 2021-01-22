//3_count_sort.cpp
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main () {
	string s = "asdf";
	for (char c : s) {
		cout << c << ",";
	}
	cout << '\n';
	vector<int> nums = {1, 5, 2, 3, 5, 6, 5};
	for (int c : nums) {
		cout << c << ",";
	}
	cout << '\n';
//auto!!!
	vector<string> num = {"1+", "5", "2", "3-"};
	for (auto c : num) {
		cout << c << ",";
	}
	cout << '\n';
	int i = 0;
	for (auto c : nums) {
		if (c == 5){
			i++;
		}
	}
	cout << i << '\n';
//algorithm library
//задание последовательности begin->end
	i = count(begin(nums), end(nums), 5);
	cout << "algorithm " << i << '\n';
//sort
	sort (begin (nums), end (nums));
	for (int c : nums) {
		cout << c << ",";
	}
	cout << '\n';
	return 0;
}
