//5_move_lines.cpp
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;

//MoveStrings source destination
void	MoveStrings(vector<string>& src, vector<string>& dest) {
	for (auto w : src)
		dest.push_back(w);
	src.clear();
}
//int		main () {
//	return 0;
//}
