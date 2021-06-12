#include <iostream>
#include <numeric>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class		Rational {
public:
    Rational() {
        N = 0;
        D = 1;
    }

    Rational(int numerator, int denominator) {
        int nod = gcd(numerator, denominator);
        N = numerator / nod;
        D = denominator / nod;
        if (N == 0)
            D = 1;
        else if ((N < 0 && D < 0) || (N > 0 && D < 0)) {
            N *= -1;
            D *= -1;
        }
    }

    int Numerator() const {
        return N;
    }

    int Denominator() const {
        return D;
    }

private:
    int N;
    int D;
};

Rational	operator+(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator());
}

Rational	operator-(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator());
}

bool		operator==(const Rational& lhs, const Rational& rhs) {
	if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
		return true;
	}
	return false;
}

Rational	operator*(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.Numerator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator());
}

Rational	operator/(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.Numerator() * rhs.Denominator(),
		lhs.Denominator() * rhs.Numerator());
}

ostream&	operator<<(ostream& stream, const Rational& rational) {
	if (stream) {
		stream << rational.Numerator() << '/' << rational.Denominator();
	}
	return stream;
}

istream&	operator>>(istream& stream, Rational& rational) {
	int n = 0, d = 1;
	char c;
	if (stream) {
		if (!(stream >> n) || !(stream >> c) || !(stream >> d))
			return stream;
		if (c == '/')
			rational = Rational(n, d);
	}
	return stream;
}

bool	operator<(const Rational& lhs, const Rational& rhs) {
	return (lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator());
}

bool	operator>(const Rational& lhs, const Rational& rhs) {
	return (lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator());
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
