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
		Route	(const string& new_sourse,
				const string& new_destination) {
					source = new_sourse;
					destination = new_destination;
					UpdateLength();
				}
		Route	() {
					source = "St. Peterburg";
					destination = "Vologda";
					UpdateLength();
			};
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
	": " << route.GetLength() << endl << endl;
}

void	ReverseRoute(Route& route) {
	string old_src = route.GetSourse();
	string old_dst = route.GetDestination();
	route.SetSourse(old_dst);
	route.SetDestination(old_src);
}

int main() {
	Route route("Moscow", "Dedovsk");
	PrintRout(route);
	ReverseRoute(route);
	PrintRout(route);

	Route r2;
	PrintRout(r2);
	ReverseRoute(r2);
	PrintRout(r2);

	PrintRout({});
	PrintRout({"Dedobsk", "Krasnogorsk"});
	return 0;
}
