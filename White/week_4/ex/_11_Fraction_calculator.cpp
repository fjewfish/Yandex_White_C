#include <iostream>
#include <numeric>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <exception>

using namespace std;

class		Rational {
public:
    Rational() {
        N = 0;
        D = 1;
    }

    Rational(int numerator, int denominator) {
		if (denominator == 0) {
			// бросаем исключение в случае нулевого знаменателя
			throw invalid_argument("Invalid argument");
		}
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
	 // проверяем делитель на 0 (что равносильно проверке на 0 его числителя)
	if (rhs.Numerator() == 0) {
		throw  domain_error("Division by zero");
	}
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

int				main() {
	Rational	lhs;
	Rational	rhs;
	char		operations;
	try {
		cin >> lhs;
		cin.ignore(1);
		cin >> operations;
		cin.ignore(1);
		cin >> rhs;
	} catch (const invalid_argument& ex) {
		cout << ex.what() << endl;
		return 0;
	}
	try {
		if (operations == '+') {
			cout << lhs + rhs;
		} else if (operations == '-') {
			cout << lhs - rhs;
		} else if (operations == '*') {
			cout << lhs * rhs;
		} else if (operations == '/') {
			cout << lhs / rhs;
		}
	} catch (const domain_error& ex) {
		cout << ex.what() << endl;
		return 0;
	}
	return 0;
}
