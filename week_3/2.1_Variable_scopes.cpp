#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	{
		int x = 5;
		cout << x;
	}

	{
		int x = 5;
		{
			cout << x;
		}
		cout << x;
	}
	//cout << x;
	cout << endl;
	string s = "Hello";
	{
		string s = "world";
		cout << s << endl;
	}
	cout << s << endl;
	return 0;
}
