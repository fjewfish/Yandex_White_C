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
		string	GetSourse() const {return source; }
		string	GetDestination() const { return destination;}
		int		GetLength() const {return length;}
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

void	PrintRout(const Route& route) {
	cout << route.GetSourse() << " - " << route.GetDestination() <<
	": " << route.GetLength() << endl;
}

void	ReverseRoute(Route& route) {
	string old_src = route.GetSourse();
	string old_dst = route.GetDestination();
	route.SetSourse(old_dst);
	route.SetDestination(old_src);
}

int main() {
	Route route;
	route.SetSourse("Moscow");
	route.SetDestination("Dubna");
	PrintRout(route);
	ReverseRoute(route);
	PrintRout(route);
	return 0;
}
