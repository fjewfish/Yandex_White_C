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
			throw invalid_argument("denominator = 0");
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
		throw  domain_error("devisor = 0");
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

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
		cout << x << endl;
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
