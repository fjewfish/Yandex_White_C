//1.4_const_link.cpp
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct	Person {
	string	name;
	string	surname;
	int		age;
};

vector<Person> GetMoscowPopulation() {
	vector<Person> staff;
	int i = 0;
	while (i++ < 500000) {
		staff.push_back({"Ivan", "Ivanov", 25});
		staff.push_back({"Denis", "Lunev", 29});
		staff.push_back({"Ivan", "Ivanov", 25});
		staff.push_back({"Denis", "Lunev", 29});
		staff.push_back({"Ivan", "Ivanov", 25});
		staff.push_back({"Denis", "Lunev", 29});
		staff.push_back({"Ivan", "Ivanov", 25});
		staff.push_back({"Denis", "Lunev", 29});
		staff.push_back({"Ivan", "Ivanov", 25});
	}
	return staff;
}

void	PrintPopulationSize (const vector<Person>& p) {
	cout << "There are " << p.size() << " people in Moscow" << endl;
}

//результат вызова фунеции не может быть передан по ссылке
//в другую функцию, но может по const ссылке
int		main () {
	auto start = steady_clock::now();
	vector<Person> people = GetMoscowPopulation();
	auto finish = steady_clock::now();
	cout << "GetMoscowPopulation start = "
		<< duration_cast<milliseconds> (finish - start).count() << endl;

	start = steady_clock::now();
	PrintPopulationSize(people);
	finish = steady_clock::now();
	cout << "PrintPopulationSize = "
		<< duration_cast<milliseconds> (finish - start).count() << endl;

	PrintPopulationSize(GetMoscowPopulation());
	return 0;
}
