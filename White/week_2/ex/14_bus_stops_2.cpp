//12_country_capital.cpp
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int				main () {
	int n;
	cin >> n;
	int number = 1;
	map<int, vector<string>> bus_stops;

	for (int j = 0; j < n; j++) {
		int N;
		cin >> N;
		bool fail = false;
		for (int i = 0; i < N; i++) {
			string stop;
			cin >> stop;
			bus_stops[number].push_back(stop);
		}
		for (const auto& buses : bus_stops) {
			if (buses.second == bus_stops[number] && buses.first != number) {
				cout << "Already exists for " << buses.first << endl;
				bus_stops.erase(number);
				number--;
				fail = true;
				break;
			}
		}
		if (!fail) {
			cout << "New bus " << number << endl;
		}
		number++;
	}
	return 0;
}

//BETTER DECISION
/*
int main() {
  int q;
  cin >> q;

  map<vector<string>, int> buses;

  for (int i = 0; i < q; ++i) {
    int n;
    cin >> n;
    vector<string> stops(n);
    for (string& stop : stops) {
      cin >> stop;
    }

    // проверяем, не существует ли уже маршрут с таким набором остановок
    if (buses.count(stops) == 0) {

      // если не существует, нужно сохранить новый маршрут;
      // его номер на единицу больше текущего количества маршрутов
      const int new_number = buses.size() + 1;
      buses[stops] = new_number;
      cout << "New bus " << new_number << endl;

    } else {
      cout << "Already exists for " << buses[stops] << endl;
    }
  }

  return 0;
}
*/
