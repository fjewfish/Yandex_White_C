#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

string	Result(const vector<string> v) {
	const int k = v.size();
	string res = v[k - 1];
	if (k > 1) {
		int i;
		res += " (";
		for (i = 1; i < k - 1; i++)
			res += v[k - i - 1] + ", ";
		res += v[k - i - 1] + ")";
	}
	return res;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
	first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
	last_names[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    string fn= "";
    string ln = "";
    for (const auto& i : first_names) {
      if (i.first <= year) {
        fn = i.second;
      }
      else
        break;
    }
    for (const auto& i : last_names) {
      if (i.first <= year) {
        ln = i.second;
      }
      else
        break;
    }
    if (!fn.size() && !ln.size())
      return "Incognito";
    else if (!fn.size())
      return ln + " with unknown first name";
    else if (!ln.size())
      return  fn + " with unknown last name";
    else
      return fn + " " + ln;
  }
  string GetFullNameWithHistory(int year) {
    // получить все имена и фамилии по состоянию на конец года year
	vector<string> fn_vector;
	vector<string> ln_vector;
	string previous = "";
	for (const auto& i : first_names) {
      if (i.first <= year) {
		  if (i.second != previous) {
		  	fn_vector.push_back(i.second);
		  	previous = i.second;
		  }
      }
      else
        break;
    }
	previous = "";
	for (const auto& i : last_names) {
      if (i.first <= year) {
		if (i.second != previous) {
        	ln_vector.push_back(i.second);
			previous = i.second;
		}
      }
      else
        break;
    }
	if (!fn_vector.size() && !ln_vector.size())
      return "Incognito";
    else if (!fn_vector.size())
      return Result(ln_vector) + " with unknown first name";
    else if (!ln_vector.size())
      return Result(fn_vector) + " with unknown last name";
    else
      return Result(fn_vector) + " " + Result(ln_vector);
  }
private:
  // приватные поля
	map<int, string> first_names;
	map<int, string> last_names;
};

//EXAMPLE 1

//int main() {
//  Person person;

//  person.ChangeFirstName(1900, "Eugene");
//  person.ChangeLastName(1900, "Sokolov");
//  person.ChangeLastName(1910, "Sokolov");
//  person.ChangeFirstName(1920, "Evgeny");
//  person.ChangeLastName(1930, "Sokolov");
//  cout << person.GetFullNameWithHistory(1940) << endl;

//  return 0;
//}

//EXAMPLE 2

//int main() {
//  Person person;

//  person.ChangeFirstName(1965, "Polina");
//  person.ChangeLastName(1967, "Sergeeva");
//  for (int year : {1900, 1965, 1990}) {
//    cout << person.GetFullNameWithHistory(year) << endl;
//  }

//  person.ChangeFirstName(1970, "Appolinaria");
//  for (int year : {1969, 1970}) {
//    cout << person.GetFullNameWithHistory(year) << endl;
//  }

//  person.ChangeLastName(1968, "Volkova");
//  for (int year : {1969, 1970}) {
//    cout << person.GetFullNameWithHistory(year) << endl;
//  }

//  person.ChangeFirstName(1990, "Polina");
//  person.ChangeLastName(1990, "Volkova-Sergeeva");
//  cout << person.GetFullNameWithHistory(1990) << endl;

//  person.ChangeFirstName(1966, "Pauline");
//  cout << person.GetFullNameWithHistory(1966) << endl;

//  person.ChangeLastName(1960, "Sergeeva");
//  for (int year : {1960, 1967}) {
//    cout << person.GetFullNameWithHistory(year) << endl;
//  }

//  person.ChangeLastName(1961, "Ivanova");
//  cout << person.GetFullNameWithHistory(1967) << endl;

//  return 0;
//}

//EXAMPLE 3

//int main() {
//  Person person;

//  person.ChangeFirstName(1965, "Polina");
//  person.ChangeFirstName(1965, "Appolinaria");

//  person.ChangeLastName(1965, "Sergeeva");
//  person.ChangeLastName(1965, "Volkova");
//  person.ChangeLastName(1965, "Volkova-Sergeeva");

//  for (int year : {1964, 1965, 1966}) {
//    cout << person.GetFullNameWithHistory(year) << endl;
//  }

//  return 0;
//}
