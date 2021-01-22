// 2.1_++--.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main () {
	int a = 11;
	int b = 3;
	cout << a / b << ' ' << a % b << endl;

	double c = 11;
	double d = 3;
	cout << c / d << endl;

	a = 6;
	b = 4;
	c = 1;
	cout << a / b + c / 0.4 << endl;

	int x = 5;
	x += 2;
	cout << x << endl;
//инкремент
	x++;
	cout << x << endl;
//декримет
	x--;
	cout << x << endl;

	c = 5;
// a до инкремента с увеличилась на 1
	a = c++;
// b после инкремента
	b = ++c;
	cout << "a = c++ = " << a << endl;
	cout << "b = ++c = " << b << endl;
	return 0;
}
