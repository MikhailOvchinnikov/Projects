#include <iostream>
#include <iomanip>
#include <exception>
#include <string>
#include <sstream>
#include <map>
#include <set>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    int GetYear() const
    {
        return year;
    }
    int GetMonth() const
    {
        return month;
    }
    int GetDay() const
    {
        return day;
    }

    void SetYear(int y)
    {
        year = y;
    }
    void SetMonth(int m)
    {
        month = m;
    }
    void SetDay(int d)
    {
        day = d;
    }
};

bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() < rhs.GetYear())
    {
        return true;
    }
    else if (lhs.GetMonth() < rhs.GetMonth())
    {
        return true;
    }
    else if (lhs.GetDay() < rhs.GetDay())
    {
        return true;
    }
    return false;
}

class Database {
private:
    map<Date, set<string>> dict;
public:
    void AddEvent(const Date& date, const string& event)
    {
        dict[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event)
    {
        
        if (dict[date].size() != 0)
        {
            dict[date].erase(event);
            return true;
        }
        return false;
    }
    int  DeleteDate(const Date& date)
    {
        int counter = 0;
        if (dict.count(date))
        {
 
            for (const auto& i : dict[date])
            {
                counter++;
            }
            dict.erase(date);
        }
        return counter;
    }

    void Find(const Date& date) const
    {
        for (const auto& i : dict.at(date))
        {
            cout << i << endl;
        }
    }

    void Print() const
    {
        for (const auto& i : dict)
        {
            for (const auto& k : i.second)
            {
                cout << setfill('0');
                cout << setw(4) << i.first.GetYear() << '-' << setw(2) << i.first.GetMonth() << '-' << setw(2) << i.first.GetDay()
                    << " " << k << endl;
            }
        }
    }
};

Date SetDate(Date& date, string& str)
{
    stringstream stream(str);

    int day, month, year;
    stream >> year;
    bool f_symbol = stream.peek() == '-';
    stream.ignore(1);
    stream >> month;
    bool s_symbol = stream.peek() == '-';
    stream.ignore(1);
    stream >> day;
    if (f_symbol && s_symbol)
    {
        if (month < 0 || month > 12)
        {
            throw "Month value is invalid: " + to_string(month);
        }
        else if (day < 0 || day > 31)
        {
            throw "Day value is invalid: " + to_string(day);
        }
        else
        {
            date.SetDay(day);
            date.SetMonth(month);
            date.SetYear(year);
        }
    }
    else
    {
        throw "Wrong date format: " + str;
    }
    return date;
}


int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        stringstream stream(command);
        Date date;
        string main_command, t_data, event;
        stream >> main_command;
        stream >> t_data;
        try
        {
        if (main_command == "Add")
        {
                date = SetDate(date, t_data);
                stream >> event;
                db.AddEvent(date, event);
        
        }
        else if (main_command == "Del")
        {
            date = SetDate(date, t_data);
            stream >> event;
            if (event.size() == 0)
            {
                cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
            }
            else if (event.size() != 0)
            {
                if (db.DeleteEvent(date, event))
                {
                    cout << "Deleted successfully" << endl;
                }
                else
                {
                    cout << "Event not found" << endl;
                }
            }
        }
        else if (main_command == "Find")
        {
            db.Find(SetDate(date, t_data));
        }
        else if (main_command == "Print")
        {
            db.Print();
        }
        else if (!main_command.empty())
        {
            cout << "Unknown command: " << main_command << endl;
        }
        }
        catch (string& ex)
        {
            cout << ex << endl;
        }
    }
    

    return 0;
}
