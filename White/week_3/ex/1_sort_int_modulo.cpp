//1_sort_int_modulo.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

int		main () {
	int n = 0;
	cin >> n;
	vector<int> A(n);
	for (auto& i : A) {
		cin >> i;
	}
	sort(begin(A), end(A), [](int l, int r) {
		return abs(l) < abs(r);
	});
	for (int x : A) {
		cout << x << " ";
	}
	return 0;
}
