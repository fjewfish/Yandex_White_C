//8_average_temperature.cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int		main () {
	int	n;
	int	N;
	int	sum = 0;

	cin >> n;
	vector<int> temperature(n);
	for (auto& i : temperature) {
		cin >> i;
		sum += i;
	}
	N = sum / n;
	sum = 0;
	for (auto i : temperature)
		if (i > N)
			sum++;
	cout << sum << endl;
	for (int i = 0; i < n; i++) {
		if (temperature[i] > N)
			cout << i << ' ';
	}
	return 0;
}
