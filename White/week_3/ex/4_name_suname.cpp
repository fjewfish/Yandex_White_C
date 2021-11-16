#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

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
private:
  // приватные поля
	map<int, string> first_names;
	map<int, string> last_names;
};


int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
