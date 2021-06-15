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
    if (lhs.GetYear() != rhs.GetYear()){
        return lhs.GetYear() < rhs.GetYear();
    }
    else if (lhs.GetMonth() != rhs.GetMonth()){
        return lhs.GetMonth() < rhs.GetMonth();
    }
    else {
        return lhs.GetDay() < rhs.GetDay();
    }
}

//bool			operator<(const Date& lhs, const Date& rhs){
//	if (lhs.GetYear() < rhs.GetYear()) {
//		return true;
//	} else if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() < rhs.GetMonth()) {
//		return true;
//	} else if (lhs.GetMonth() == rhs.GetMonth() && lhs.GetYear() == rhs.GetYear() && lhs.GetDay() < rhs.GetDay()) {
//		return true;
//	}
//	return false;
//}

bool			operator==(const Date& lhs, const Date& rhs){
	if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay())
		return true;
	return false;
}

ostream&		operator<<(ostream& stream, const Date& date) {
	stream << setfill('0');
	stream	<< setw(4) << date.GetYear() << '-'
			<< setw(2) << date.GetMonth() << '-'
			<< setw(2) << date.GetDay();
	return stream;
}

//class			Database {
//public:
//	void AddEvent(const Date& date, const string& event) {
//		if (event.size()) {
//			set<string> ex;
//			if (db.count(date))
//				ex = db[date];
//			ex.insert(event);
//			db[date] = ex;
//		}
//	}
//	bool DeleteEvent(const Date& date, const string& event) {
//		if (db[date].erase(event)) {
//			cout << "Deleted successfully" << endl;
//			return true;
//		} else {
//			cout << "Event not found" << endl;
//			return false;
//		}
//	}
//	int  DeleteDate(const Date& date) {
//		int N = db[date].size();
//		db[date].clear();
//		db.erase(date);
//		cout << "Deleted " << N << " events" << endl;
//		return N;
//	}

//	void Find(const Date& date) const {
//		if (db.count(date)) {
//			for (const auto& i : db.at(date)){
//				cout << i << endl;
//			}
//		}
//	}

//	void Print() const {
//		for(const auto& date : db) {
//			for(const auto& event : date.second) {
//				cout << date.first << " " << event << endl;
//			}
//		}
//	}
//private:
//	map<Date, set<string>> db;
//};


class Database
        {
public:
    void AddEvent(const Date& date, const std::string& event)
    {
        if (!event.empty())
        {
            records[date].insert(event);
        }
    }
//	bool DeleteEvent(const Date& date, const string& event) {
//		if (db[date].erase(event)) {
//			cout << "Deleted successfully" << endl;
//			return true;
//		} else {
//			cout << "Event not found" << endl;
//			return false;
//		}
//	}
    bool DeleteEvent(const Date& date, const std::string& event)
    {
        if (records.count(date) > 0 && records[date].count(event) > 0)
        {
            records[date].erase(event);
			cout << "Deleted successfully" << endl;
            return true;
        }
		cout << "Event not found" << endl;
        return false;
    }
//	int  DeleteDate(const Date& date) {
//		int N = db[date].size();
//		db[date].clear();
//		db.erase(date);
//		cout << "Deleted " << N << " events" << endl;
//		return N;
//	}
    int  DeleteDate(const Date& date)
    {
        int to_del = 0;
        if (records.count(date) > 0)
        {
            to_del = records.at(date).size();
            records.erase(date);
        }
		cout << "Deleted " << to_del << " events" << endl;
        return to_del;
    }
//	void Find(const Date& date) const {
//		if (db.count(date)) {
//			for (const auto& i : db.at(date)){
//				cout << i << endl;
//			}
//		}
//	}
    void Find(const Date& date) const
    {
        std::set<std::string> result;
        if (records.count(date) > 0)
        {
            for (const auto& i : records.at(date))
				cout << i << endl;
        }
    }

//	void Print() const {
//		for(const auto& date : db) {
//			for(const auto& event : date.second) {
//				cout << date.first << " " << event << endl;
//			}
//		}
//	}
//private:
//	map<Date, set<string>> db;
//};
    void Print() const
    {
        for (const auto& r : records)
        {
            for (auto s : r.second)
            {
                std::cout << r.first << ' ' << s << std::endl;
            }
        }
    }

private:
    std::map<Date, std::set<std::string>> records;
};


void			PrintVector_str(const vector<string>& v) {
	for (const auto& i : v) {
		cout << i << "_";
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
//PrintVector_str(words);
	return words;
}

int			EnsureNextSymbolAndSkip (stringstream& stream, const string& str, const int& situation) {
	if (situation == 1 && stream.peek() != '-') {
		stringstream ss;
		ss << "Wrong date format: " << str;
		throw runtime_error(ss.str());
		return 0;
	}
	if (situation == 2 && ((stream.peek() >= '0' && stream.peek() <= '9') ||
							stream.peek() == '-' || stream.peek() == '+'))
		return 1;
	if (situation == 2) {
		stringstream ss;
		ss << "Wrong date format: " << str;
		throw runtime_error(ss.str());
	}
	return 0;
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
		stringstream ss;
		ss << "Wrong date format: " << str;
		throw runtime_error(ss.str());
	}
	return Date{Year(y), Month(m), Day(d)};
}

stringstream	Tests();

int				main() {
	Database db;
	string str;
	//stringstream test = Tests();
try {
	//while (getline(test, str)) {
	while (getline(cin, str)) {
		vector<string> commands = StrToWords(str);
		if (commands.size()) {
			if (commands[0] == "Print" && commands.size() == 1) {
				db.Print();
			} else if(commands[0] != "Add" && commands[0] != "Del" && commands[0] != "Find") {
				//cout << "Unknown command: " << commands[0] << endl;
				//break;
				stringstream ss;
				ss << "Unknown command: " << commands[0];
				throw runtime_error(ss.str());
			} else {
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
				//else {
				//	cout << "Unknown command: " << commands[0];
				//	break;
				//}
			}
		}
	}

} catch (const exception& ex) {
	cout << ex.what() << endl;
}
	return 0;
}


stringstream	Tests() {
	stringstream stream;
	//stream << "" << endl;
	//cout << "\nBASE TESTS:\n";
	//stream << "Add 0-1-2 event1" << endl;
	//stream << "Add 1-2-3 event2" << endl;
	//stream << "Find 0-1-2" << endl;
	//stream << "" << endl;
	//stream << "Del 0-1-2" << endl;
	//stream << "Print" << endl;
	//stream << "Del 1-2-3 event2" << endl;
	//stream << "Del 1-2-3 event2" << endl;
	//stream << "Add 0-13-32 event1" << endl;

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
	//stream << "Add 1-1- event" << endl;
	stream << "Add 1-2-1 event" << endl;
	stream << "Print" << endl;

	return stream;
}
