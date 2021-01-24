//9_binary_numbers.cpp
#include <iostream>
#include <vector>
using namespace std;

int main () {
	int n;
	int i;
	vector<int> result;

	cin >> n;
	while (n > 0) {
		result.push_back(n % 2);
		n /= 2;
	}
	i = result.size() - 1;
	while (i >= 0)
	{
		cout << result[i];
		i--;
	}
	return 0;
}
