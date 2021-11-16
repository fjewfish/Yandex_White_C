//16_map_values.cpp
//#include <iostream>
//#include <string>
//#include <iostream>
//#include <map>
//#include <vector>
//#include <set>
//using namespace std;

set<string>		BuildMapValuesSet(const map<int, string>& m) {
	set<string>	result;

	for (const auto& map_elem : m) {
		result.insert(map_elem.second);
	}
	return result;
}

//int				main () {
//	set<string>	values = BuildMapValuesSet({
//    {1, "odd"},
//    {2, "even"},
//    {3, "odd"},
//    {4, "even"},
//    {5, "odd"}
//	});
//	for (const string& value : values) {
//	cout << value << endl;
//	}
//	return 0;
//}
