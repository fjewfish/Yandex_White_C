//1.3_pointer_to_function.cpp
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void	Swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void	Sort(vector<int>& v) {
	sort (begin(v), end(v));
}

int		main () {
	int a = 1;
	int b = 3;
	cout << a << ' ' << b << endl;
	Swap(a, b);
	cout << "swap -> " << a << ' ' << b << endl;

	vector<int> nums = {3, 6, 43, 5, 9, 340};
	Sort(nums);
	for (auto x : nums) {
		cout << x << ' ';
	}
	return 0;
}
