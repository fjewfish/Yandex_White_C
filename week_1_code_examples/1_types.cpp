//types.cpp
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

struct Person
{
	string name;
	string surname;
	int age;
};


int main () {
	int x = -5;
	double pi = 3.14;
	bool logical_valur = false;
	char symbol = 'Z';

	string hw = "Hello, world";

	vector<int> nums = {1, 3, 5, 7};

	cout << nums.size();

	map<string, int> name_to_value;
	name_to_value["one"] = 1;
	name_to_value["two"] = 2;

	cout << "two is " << name_to_value["two"];

	vector<Person> staff;
	staff.push_back({"Ivan", "Ivanov", 25});
	staff.push_back({"Denis", "Lunev", 29});

	cout << staff[1].name;

	return 0;
}
