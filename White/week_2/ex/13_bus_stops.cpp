//12_country_capital.cpp
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

//Заметьте, что при этом не всегда удаётся передавать словари по константным ссылкам:
//это происходит из-за того, что использование квадратных скобок (например,
//в коде stops_to_buses[stop]) теоретически может изменить словарь.
//В этой ситуации стоило бы использовать метод at вместо квадратных скобок

void			BUSES_FOR_STOP(map<string, vector<string>>& stop_buses) {
	string stop;
	cin >> stop;
	if (stop_buses.count(stop) == 0) {
		cout << "No stop";
		stop_buses.erase(stop);
	}
	else {
		for (const auto& bus : stop_buses[stop])
			cout << bus << ' ';
	}
	cout << endl;
}

void			STOPS_FOR_BUS(map<string, vector<string>>& bus_stops, map<string, vector<string>>& stop_buses) {
	string bus;
	cin >> bus;
	if (bus_stops.count(bus) == 0) {
		cout << "No bus" << endl;
		bus_stops.erase(bus);
	} else {
		for (const auto& stop : bus_stops[bus]) {
			cout << "Stop " << stop << ": ";
			if (stop_buses[stop].size() == 1)
				cout << "no interchange";
			else {
				for (const auto& buses : stop_buses[stop]) {
					if (buses != bus)
						cout << buses << ' ';
				}
			}
			cout << endl;
		}
	}
}

void			ALL_BUSES(map<string, vector<string>>& bus_stops) {
	if (bus_stops.size()) {
		for (const auto& bus_map : bus_stops) {
			cout << "Bus " << bus_map.first << ": ";
			for (const auto& stop : bus_map.second) {
				cout << stop << " ";
			}
			cout << endl;
		}
	} else
		cout << "No buses" << endl;
}

int				main () {
	int n;
	cin >> n;
	map<string, vector<string>> bus_stops, stop_buses;

	for (int j = 0; j < n; j++) {
		string command;
		cin >> command;
		if (command == "NEW_BUS") {
			string bus;
			int stops_count;
			cin >> bus >> stops_count;
			while (stops_count > 0) {
				string stop;
				cin >> stop;
				bus_stops[bus].push_back(stop);
				stop_buses[stop].push_back(bus);
				stops_count--;
			}
		}
		else if (command == "BUSES_FOR_STOP")
			BUSES_FOR_STOP(stop_buses);
		else if (command == "STOPS_FOR_BUS")
			STOPS_FOR_BUS(bus_stops, stop_buses);
		else if (command == "ALL_BUSES")
			ALL_BUSES(bus_stops);
	}
	return 0;
}
