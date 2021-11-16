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

//Prototype for TESTS
stringstream	Tests();

void			Error_write(const string& message, const string& str) {
	stringstream ss;

	ss << message << str;
	throw logic_error(ss.str());
}

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
	if (month < 1 || month > 12)
		Error_write("Month value is invalid: ", to_string(month));
	else if (day < 1 || day > 31)
		Error_write("Day value is invalid: ", to_string(day));
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
	} else if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() < rhs.GetMonth()) {
		return true;
	} else if (lhs.GetMonth() == rhs.GetMonth() && lhs.GetYear() == rhs.GetYear() && lhs.GetDay() < rhs.GetDay()) {
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

class			Database {
public:

	void		AddEvent(const Date& date, const string& event) {
		if (!event.empty())
			db[date].insert(event);
	}

	bool		DeleteEvent(const Date& date, const string& event) {
		if (db[date].erase(event)) {
			cout << "Deleted successfully" << endl;
			return true;
		} else {
			cout << "Event not found" << endl;
			return false;
		}
	}

	int			DeleteDate(const Date& date) {
		int N = 0;
		if (db.count(date) > 0)
		{
			N = db.at(date).size();
			db.erase(date);
		}
		cout << "Deleted " << N << " events" << endl;
		return N;
	}

	void		Find(const Date& date) const {
		if (db.count(date)) {
			for (const auto& i : db.at(date)){
				cout << i << endl;
			}
		}
	}

	void		Print() const {
		for(const auto& date : db) {
			for(const auto& event : date.second) {
				cout << date.first << " " << event << endl;
			}
		}
	}
private:
	map<Date, set<string>> db;
};

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

void			EnsureNextSymbolAndSkip (stringstream& stream, const string& str, const int& situation) {
	if (situation == 1 && stream.peek() != '-')
		Error_write("Wrong date format: ", str);
	else if (situation == 2 && ((stream.peek() < '0' || stream.peek() > '9') &&
							stream.peek() != '-' && stream.peek() != '+')) {
		Error_write("Wrong date format: ", str);
	}
}

Date			ReadDate(const string& str){
	int d = 0, m = 0, y = 0;
	string end = "";

	stringstream stream(str);
	EnsureNextSymbolAndSkip(stream, str, 2);
	stream >> y;
	EnsureNextSymbolAndSkip(stream, str, 1);
	stream.ignore(1);
	EnsureNextSymbolAndSkip(stream, str, 2);
	stream >> m;
	EnsureNextSymbolAndSkip(stream, str, 1);
	stream.ignore(1);
	EnsureNextSymbolAndSkip(stream, str, 2);
	stream >> d >> end;
	if (end.size()) {
		Error_write("Wrong date format: ", str);
	}
	return Date{Year(y), Month(m), Day(d)};
}

int				main() {
	Database db;
	string str;
	//stringstream test = Tests(); //ONLY FOR TEST STREAM
	try {
		//while (getline(test, str)) { //ONLY FOR TEST STREAM
		while (getline(cin, str)) {
			vector<string> commands = StrToWords(str);
			if (commands.size()) {
				if (commands.size() == 1 && commands[0] == "Print") {
					db.Print();
				} else if(commands[0] != "Add" && commands[0] != "Del" && commands[0] != "Find")
					Error_write("Unknown command: ", commands[0]);
				else {
					Date date = ReadDate(commands[1]);
					if (commands[0] == "Add" && commands.size() == 3) {
						db.AddEvent(date, commands[2]);
					} else if (commands[0] == "Del") {
						if(commands.size() == 2)
							db.DeleteDate(date);
						else if (commands.size() == 3)
							db.DeleteEvent(date, commands[2]);
					} else if (commands[0] == "Find" && commands.size() == 2) {
						db.Find(date);
					}
				}
			}
		}
	} catch (const exception& ex) {
	cout << ex.what() << endl;
	}
	return 0;
}

//TESTING STREAM
stringstream	Tests() {
	stringstream stream;
	stream << "" << endl;
	cout << "\nBASE TESTS:\n";
	stream << "Add 0-1-2 event1" << endl;
	stream << "Add 1-2-3 event2" << endl;
	stream << "Find 0-1-2" << endl;
	stream << "" << endl;
	stream << "Del 0-1-2" << endl;
	stream << "Print" << endl;
	stream << "Del 1-2-3 event2" << endl;
	stream << "Del 1-2-3 event2" << endl;
	stream << "Add 0-13-32 event1" << endl;

	//cout << "\nDATE:\n";
	//stream << "Add 1-1-19 fan" << endl;
	//stream << "Add -1-1-1 fan" << endl;
	//stream << "Add 1--1-1 fan" << endl;
	//stream << "Add 1---1-1 fan" << endl;
	//stream << "Add 1-+1-+1 fan" << endl;
	//stream << "Add 2-1-1 fan" << endl;
	//stream << "Add 2-1-2 fan" << endl;
	//stream << "Add 2-1-2 fa" << endl;
	//stream << "Add 2-1-3 fa" << endl;
	//stream << "Add 2-1-20 wtf" << endl;
	//stream << "Add 20-1-2 ___" << endl;
	//stream << "Add 2-10-2 __-" << endl;
	//stream << "Print" << endl;

	//stream << "Add 1997-09-03 fan" << endl;
	//stream << "Add 1997-09-03 fa" << endl;
	//stream << "Add 1997-09-04 fa" << endl;
	//stream << "Add 1997-09-30 wtf" << endl;
	//stream << "Add 2-1-20 fa" << endl;

	//stream << "Add 1997-09-30 wtf" << endl;
	//stream << "Add 1997-09-20 wtf1" << endl;
	//stream << "Add 1997-09-1 wtf" << endl;
	//stream << "Add 1997-09-2 wtf1" << endl;
	//stream << "Print" << endl;

	//Date a = ReadDate("1997-09-1");
	//a.PrintDate();
	//Date b = ReadDate("1997-09-2");
	//b.PrintDate();
	//if (a < b)
	//	cout << "Nice\n";

	//stream << "Add 1997-09-30  " << endl;
	//stream << "Add 1997-09-30  /   " << endl;
	//stream << "Add 1997-09-20 wtf1" << endl;
	//stream << "Add 1997-09-1 wtf" << endl;
	//stream << "Add 1997-09-2 wtf1" << endl;
	//stream << "Add 1997-09-30 asdf" << endl;
	//stream << "Add 1997-09-20 001" << endl;
	//stream << "Add 1997-09-1 0d" << endl;
	//stream << "Add 1997-09-1 asdf" << endl;
	//stream << "Add 1997-09-1 001" << endl;
	//stream << "Add 1997-09-2 wd" << endl;
	//stream << "Print" << endl;
	//stream << "Find 1997-09-1" << endl;
	stream << "Add 1-1- event" << endl;
	stream << "Add 1-2-1 event" << endl;
	stream << "Print" << endl;

	return stream;
}
