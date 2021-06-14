#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>

using namespace std;

/*
** - добавление события:                        Add Дата Событие
** - удаление события:                          Del Дата Событие
** - удаление всех событий за конкретную дату:  Del Дата
** - поиск событий за конкретную дату:          Find Дата
** - печать всех событий за все даты:           Print
*/

struct			Day
{
	int value;
	explicit Day(int new_value) {
		value = new_value;
	}
};

struct			Month
{
	int value;
	explicit Month(int new_value) {
		value = new_value;
	}
};

struct			Year
{
	int value;
	explicit Year(int new_value) {
		value = new_value;
	}
};

void			CheckMonthDay_valid(const int& month, const int& day) {
	stringstream ss;
	if (month < 1 || month > 12){
		ss << "Month value is invalid: " << month;
		throw runtime_error(ss.str());
	} else if (day < 1 || day > 31){
		ss << "Day value is invalid: " << day;
		throw runtime_error(ss.str());
	}
}

class			Date {
public:
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
	Date(Year new_year, Month new_month, Day new_day) {
		CheckMonthDay_valid(new_month.value, new_day.value);
		year = new_year.value;
		month = new_month.value;
		day = new_day.value;
	}
	void PrintDate() const {
		cout << year << "/" << month << "/" << day << endl;
	}
private:
	int year;
	int month;
	int day;
};

bool			operator<(const Date& lhs, const Date& rhs){
	if (lhs.GetYear() < rhs.GetYear()) {
		return true;
	} else if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() < rhs.GetMonth())
			return true;
	} else if (lhs.GetMonth() == rhs.GetMonth()) {
		if (lhs.GetDay() < rhs.GetDay())
			return true;
	}
	return false;
}

ostream&		operator<<(ostream& stream, const Date& date) {
	stream << setfill('0');
	stream	<< setw(4) << date.GetYear() << '-'
			<< setw(2) << date.GetMonth() << '-'
			<< setw(2) << date.GetDay();
	return stream;
}

void			PrintSet(const set<string>& s) {
	int n = s.size();
	for (const auto& x : s) {
		cout << x;
		if (--n)
			cout << ' ';
	}
	cout << endl;
}

class			Database {
public:
	void AddEvent(const Date& date, const string& event) {
		db[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event) {
		if (db[date].erase(event)) {
			cout << "Deleted successfully" << endl;
			return true;
		} else {
			cout << "Event not found" << endl;
			return false;
		}
	}
	int  DeleteDate(const Date& date) {
		int N = db[date].size();
		db[date].clear();
		db.erase(date);
		cout << "Deleted " << N << " events" << endl;
		return N;
	}

	void Find(const Date& date) const {
		PrintSet(db.at(date));
	}

	void Print() const {
		for(const auto& date : db) {
			for(const auto& event : date.second) {
				cout << date.first << " " << event << endl;
			}
		}
	}
private:
	map<Date, set<string>> db;
};

void			PrintVector_str(const vector<string>& v) {
	for (const auto& i : v) {
		cout << i << " ";
	}
	cout << endl;
}

vector<string>	StrToWords(const string& str) {
	vector<string> words;
	string word = "";

	for (const char& i : str) {
		if (i == ' ') {
			if (word.length()) {
				words.push_back(word);
			}
			word.clear();
		} else {
			word += i;
		}
	}
	if (word.length()) {
		words.push_back(word);
	}
	return words;
}

void			EnsureNextSymbolAndSkip (stringstream& stream, const string& str) {
	if (stream.peek() != '-') {
		stringstream ss;
		ss << "Wrong date format: " << str;
		throw runtime_error(ss.str());
	}
}

Date			ReadDate(const string& str){
	int d = 0, m = 0, y = 0;
	string end = "";

	stringstream stream(str);
	stream >> y;
	EnsureNextSymbolAndSkip(stream, str);
	stream.ignore(1);
	stream >> m;
	EnsureNextSymbolAndSkip(stream, str);
	stream.ignore(1);
	stream >> d >> end;
	if (end.size()) {
		stringstream ss;
		ss << "Wrong date format: " << str;
		throw runtime_error(ss.str());
	}
	return Date{Year(y), Month(m), Day(d)};
}

int				main() {
	Database db;

	string str;
try {
	while (getline(cin, str)) {
		vector<string> commands = StrToWords(str);
		if (commands.size()) {
			if (commands[0] == "Print") {
				db.Print();
			} else {
				Date date = ReadDate(commands[1]);
				if (commands[0] == "Add") {
					db.AddEvent(date, commands[2]);
				} else if (commands[0] == "Del") {
					if(commands.size() == 2)
						db.DeleteDate(date);
					else if (commands.size() == 3)
						db.DeleteEvent(date, commands[2]);
				} else if (commands[0] == "Find") {
					db.Find(date);
				} else {
					cout << "Unknown command: " << commands[0];
					break;
				}
			}
		}
	}

} catch (const exception& ex) {
	cout << ex.what() << endl;
}

	return 0;
}
