//1_factorial.cpp
//#include <iostream>
//using namespace std;

int		Factorial(int x) {
	int fac = 1;

	if (x <= 0)
		return (1);
	for (int i = 1; i <= x; i++)
		fac *= i;
	return fac;
}

//RECURSIVE
//int Factorial(int x) {
//  if (x <= 1) {
//    return 1;
//  } else {
//    return x * Factorial(x - 1);  // вычисляем факториал от x-1 и умножаем на x
//  }
//}

//int		main() {
//	int x;
//	cin >> x;
//	cout << Factorial(x);
//}
