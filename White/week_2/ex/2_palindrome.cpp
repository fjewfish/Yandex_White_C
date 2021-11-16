//2_palindrome.cpp
//#include <string>
//#include <iostream>
//using namespace std;

bool	IsPalindrom(string str) {
	int size = str.size();
	for (int i = 0; i < size / 2; i++) {
		if (str[i] != str[size - i - 1])
			return false;
	}
	return true;
}

//int		main() {
//	string str;
//	cin >> str;
//	cout << IsPalindrom(str);
//}
