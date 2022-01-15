#include <iostream>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>

using namespace std;

class Date {
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

    Date(const int& jahr, const int& monat, const int& tag) {
        if (monat > 0 && monat < 13) {
            if (tag > 0 && tag < 32) {
                year = jahr;
                month = monat;
                day = tag;
            }
            else {
                throw out_of_range("Day value is invalid: " + to_string(tag) + "\n");
            }
        }
        else {
            throw out_of_range("Month value is invalid: " + to_string(monat) + "\n");
        }
    }

private:
    int day, month, year;
};

ostream& operator << (ostream& stream, const Date& date)
{
    stream << setfill('0') << setw(4) << to_string(date.GetYear());
    stream << "-";
    stream << setfill('0') << setw(2) << std::to_string(date.GetMonth());
    stream << "-";
    stream << setfill('0') << setw(2) << to_string(date.GetDay());
    return stream;
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    }
    else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    }
    else {
        return lhs.GetDay() < rhs.GetDay();
    }
}

Date ParseDate(const string& date)
{
    istringstream date_stream(date);
    bool flag = true;

    int year;
    flag = flag && (date_stream >> year);
    flag = flag && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    flag = flag && (date_stream >> month);
    flag = flag && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    flag = flag && (date_stream >> day);
    flag = flag && date_stream.eof();

    if (!flag)
    {
        throw logic_error("Wrong date format: " + date);
    }
    return Date(year, month, day);
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        if (!event.empty())
        {
            events_per_date[date].insert(event);
        }
    }

    bool DeleteEvent(const Date& date, const string& event) {
        if (events_per_date.count(date) > 0 && events_per_date[date].count(event) > 0)
        {
            events_per_date[date].erase(event);
            return true;
        }
        return false;
    }

    int  DeleteDate(const Date& date) {
        int num_of_delete_events = 0;

        if (events_per_date.count(date) > 0) {
            num_of_delete_events = events_per_date.at(date).size();
            events_per_date.erase(date);
        }
       
      return num_of_delete_events;
        
    }

    set<string> Find(const Date& date) const {
        set<string> rez;
        if (events_per_date.count(date) > 0)
        {
            rez = events_per_date.at(date);
        }
        return rez;
    }

    void Print() const {
        for (const auto& w : events_per_date) {
            for (const auto& s : w.second) {
                cout << w.first << " " << s << endl;
            }
        }
    }

private:
    map<Date, set<string>> events_per_date;
};

int main() {
    try {
        Database db;
        string command;

        while (getline(cin, command)) {
            if (command == "")continue;
            stringstream input(command);
            string operation;
            input >> operation;
            if (operation == "Add") {
                string date_string, event;
                input >> date_string >> event;
                const Date date = ParseDate(date_string);
                if (event != "" || event != " ") {
                    db.AddEvent(date, event);
                }
            }
            else if (operation == "Del") {
                string date_string, event;
                input >> date_string;
                if (!input.eof()) {
                    input >> event;
                }
                const Date date = ParseDate(date_string);
                if (event.empty()) {
                    const int num_of_events = db.DeleteDate(date);
                    cout << "Deleted " << num_of_events << " events\n";
                }
                else {
                    if (db.DeleteEvent(date, event)) {
                        cout << "Deleted successfully\n";
                    }
                    else {
                        cout << "Event not found\n";
                    }
                }
            }
            else if (operation == "Find") {
                string date_string, event;
                input >> date_string;
                const Date date = ParseDate(date_string);
                set<string>events = db.Find(date);
                for (const string& w : events) {
                    cout << w << endl;
                }

            }
            else if (operation == "Print") {
                db.Print();
            }
            else {
                cout << "Unknown command: " << operation << endl;
            }
        }
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }
    return 0;
}