//3_selection_of_palindromes.cpp
//#include <vector>
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

vector<string>	PalindromFilter( vector<string> words, int minLength) {
	vector<string> result;

	for (auto i : words) {
		if (i.size() >= minLength && IsPalindrom(i)) {
			result.push_back(i);
		}
	}
	return result;
}

//int		main() {
//	string str;
//	cin >> str;
//	cout << IsPalindrom(str);
//}
