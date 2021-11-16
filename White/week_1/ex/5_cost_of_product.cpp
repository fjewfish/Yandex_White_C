//5_cost_of_product.cpp
#include <iostream>
using namespace std;

//N - original value
//A - discount X
//X - first discount
//B - discount Y
//Y - second discount
int main () {
	double N, A, B, X, Y;
	cin >> N >> A >> B >> X >> Y;
	if (N < 0)
		return 0;
	if (A < B && X <= 100 && X >= 0 && Y <= 100 && Y >= 0) {
		if (N > B)
			N *= (100 - Y) / 100;
		else if (N > A)
			N *= (100 - X) / 100;
	}
	cout << N << endl;
	return 0;
}
