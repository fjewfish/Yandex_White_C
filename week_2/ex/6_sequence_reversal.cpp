//6_sequence_reversal.cpp
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;

 void	Reverse(vector<int>& v) {
	int size = v.size();
	for (int i = 0; i < size / 2; i++) {
		int save = v[i];
		v[i] = v[size - i - 1];
		v[size - i - 1] = save;
	}
 }

//int		main () {
//	return 0;
//}
