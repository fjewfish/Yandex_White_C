#include <iostream>
#include <vector>
#include <string>
using namespace std;

//example
int ComputeDistance (const string& sourse, const string& destination) {
	return (int)sourse[0] * (int)destination[0];
};

class Route {
	public:
		string	GetSourse() {return source; }
		string	GetDestination() { return destination;}
		int		GetLength() {return length;}
		void SetSourse(const string& new_sourse) {
			source = new_sourse;
			UpdateLength();
		}
		void SetDestination(const string& new_destination) {
			destination = new_destination;
			UpdateLength();
		}
	private:
		string source;
		string destination;
		int length;
		void UpdateLength() {
			length = ComputeDistance(source, destination);
		}
};

int main() {
	Route route;
	route.SetSourse("Moscow");
	route.SetDestination("Dubna");
	cout << "Route from " <<
		route.GetSourse() << " to " <<
		route.GetDestination() << " is " <<
		route.GetLength() << " meters long\n";
	return 0;
}
