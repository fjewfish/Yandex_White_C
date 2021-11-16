#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Duration {
	int hour;
	int min;

	Duration(int h = 0, int m = 0) {
		hour = h;
		min = m;
	}
};

// !!! !!! !!! !!! !!!
ostream&	operator<<(ostream& stream, const Duration& duration) {
	stream << setfill('0');
	stream	<< setw(2) << duration.hour << ':'
			<< setw(2) << duration.min;
	return stream;
}

istream& operator>>(istream& stream, Duration& duration) {
	stream >> duration.hour;
	stream.ignore(1);
	stream >> duration.min;
	return stream;
}


Duration ReadDuraton(istream& stream) {
	int h = 0;
	int m = 0;
	stream >> h;
	stream.ignore(1);
	stream >> m;
	return Duration{h, m};
}

void	PrintDuration(ostream& stream, const Duration& duration) {
	stream << setfill('0');
	stream	<< setw(2) << duration.hour << ':'
			<< setw(2) << duration.min;
}

int		main() {
	stringstream dur_ss("01:50");
	Duration dur1 = ReadDuraton(dur_ss);
	PrintDuration(cout, dur1);

	cout << endl;

	stringstream dur_qq("12:01");
	Duration dur2;
	dur_qq >> dur2;
	cout << endl << dur2 << endl;
	return 0;
}
