#include <iostream>
#include <numeric>
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

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
