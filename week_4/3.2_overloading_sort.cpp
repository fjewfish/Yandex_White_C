#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct		Duration {
	int hour;
	int min;

	Duration(int h = 0, int m = 0) {
		int total = h * 60 + m;
		hour = total / 60;
		min = total % 60;
	}
};

ostream&	operator<<(ostream& stream, const Duration& duration) {
	stream << setfill('0');
	stream	<< setw(2) << duration.hour << ':'
			<< setw(2) << duration.min;
	return stream;
}

istream&	operator>>(istream& stream, Duration& duration) {
	stream >> duration.hour;
	stream.ignore(1);
	stream >> duration.min;
	return stream;
}

Duration	operator+(const Duration& lhs, const Duration& rhs) {
	return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

bool		operator<(const Duration& lhs, const Duration& rhs) {
	if (lhs.hour == rhs.hour)
		return lhs.min < rhs.min;
	else
		return lhs.hour < rhs.hour;
}

void		PrintVector(const vector<Duration>& durs, const string& title ) {
	cout << title << ":  ";
	for (const auto& i : durs) {
		cout << i << "  ";
	}
	cout << endl;
}

int			main() {
	stringstream dur_ss("00:50");
	Duration dur1;
	dur_ss >> dur1;
	Duration dur2 {19, 55};
	Duration dur3 = dur1 + dur2;
	vector<Duration> dur_v {
		dur3, dur1, dur2
	};
	PrintVector(dur_v, "NOT sorted");
	sort(begin(dur_v), end(dur_v));
	PrintVector(dur_v, "Sorted!!!!");
	return 0;
}
