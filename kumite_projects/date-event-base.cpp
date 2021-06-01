#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <exception>

/*
Final project of the 1 / 5 course of the specialization.
A simple Date-Event database.
Supports dates of format yyyy-mm-dd. 1 <= mm <= 12; 1 <= dd <= 31.
Months, leap years and complex (i.e. multiline) requests to be added later.
Processes an istream of commands until over.
*/

using namespace std;

class Date {
    public:
        Date() {}
        Date(int y, int m, int d) {
            year_ = y;
            if (m < 1 || m > 12) {  // if month not in [1: 12]
                throw range_error("Month value is invalid: " + to_string(m));
            } else if (d < 1 || d > 31) {  // if day not in [1: 31]
                throw range_error("Day value is invalid: " + to_string(d));
            } else {  // if everything else is okay
                year_ = y;
                month_ = m;
                day_ = d;
            }
        }
        int GetYear() const {
            return year_;
        }
        int GetMonth() const {
            return month_;
        }
        int GetDay() const {
            return day_;
        }
    private:
        int year_ = 0;
        int month_ = 1;
        int day_ = 1; 
};

istream& operator >> (istream& input, Date& date) {
    // Overloads an >> operator for a date string to a Date object.
    // Correct string format: y-m-d, no extra symbols before y and after d are allowed.
    string to_parse;
    input >> to_parse;

    if (!to_parse.empty()) {    
        int year, month, day;
        char sep1, sep2;

        istringstream ss(to_parse);

        ss >> year >> sep1 >> month >> sep2;

        if (!(ss >> day)) { throw runtime_error("Wrong date format: " + to_parse); }
        if (!ss.eof()) { throw runtime_error("Wrong date format: " + to_parse); }

        if (sep1 == '-' && sep2 == '-') {
            date = Date(year, month, day);
        }
        else {
            throw runtime_error("Wrong date format: " + to_parse);
        }
    }
    return input;
}

ostream& operator << (ostream& output, Date date) {
    output << setw(4) << setfill('0') << date.GetYear() << '-'
           << setw(2) << setfill('0') << date.GetMonth() << '-'
           << setw(2) << setfill('0') << date.GetDay();
    return output;
}

bool operator < (const Date& ld, const Date& hd) {
  return vector<int>{ld.GetYear(), ld.GetMonth(), ld.GetDay()} <
      vector<int>{hd.GetYear(), hd.GetMonth(), hd.GetDay()};
}

class Database {
    public:

        void AddEvent(const Date& date, const string& event) {
            // cin Add date event
            // Adds an event for a given date in a database.
            db[date].insert(event);
        }

        bool DeleteEvent(const Date& date, const string& event) {
            // cin Delete date event
            // Deletes an event from a given date in a database.
            if (db[date].count(event) == 1) {
                db[date].erase(event);
                return true;
            } else {  // no events for a given date
                return false;
            }
        }

        int DeleteDate(const Date& date) {
            // cin Delete date
            // Deletes all the events for a given date in a database
            int n = db[date].size();
            db.erase(date);
            return n;
        }

        void Find(const Date& date) const {
            // cin Find date
            // Prints all the events for a given date in an alphabet order
            if (db.count(date) == 1) {
                for (auto event : db.at(date)) {
                    cout << event << endl;
                }
            }
        }

        void Print() const {
            // cin Print
            // Prints all (date - event) pairs in a table in chronological -> alphabetic order.
            for (auto item : db) {
                for (string event : item.second) {
                    cout << item.first << ' ' << event << endl;
                }
            }
        }

    private:
        map<Date, set<string>> db;

};

int main() {
    try {
        Database db;
        string command;
        while (getline(cin, command)) {
            istringstream ss(command);
            string cmd;
            ss >> cmd;
            if (cmd == "Print") {
                db.Print();
            } else if (set<string>{"Add", "Del", "Find"}.count(cmd) == 1) {
                string event;
                Date date;
                ss >> date >> event;
                if (cmd == "Find") {
                    db.Find(date);
                } else if (cmd == "Add") {
                    db.AddEvent(date, event);
                } else {  // if command == "Del"
                    if (event.empty()) {
                        int n = db.DeleteDate(date);
                        cout << "Deleted " << n << " events" << endl;
                    } else {
                        bool deleted = db.DeleteEvent(date, event);
                        if (deleted) { cout << "Deleted successfully" << endl;
                        } else { cout << "Event not found" << endl; }
                    }
                }
            } else if (command.empty()) {
            } else {  // if command is not recognized
                throw runtime_error("Unknown command: " + cmd);
            }
        }
    } catch (runtime_error& err) {
        cout << err.what() << endl;
    }
  return 0;
}
