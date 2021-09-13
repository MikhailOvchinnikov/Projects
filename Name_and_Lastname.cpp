

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <typeinfo>

using namespace std;
class Person {
private:
    struct FullName
    {
        std::string firstname;
        std::string lastname;
    };
    std::map<int, FullName> hist_pers;

public:
    Person(std::string name, std::string lastname, int year)
    {

        hist_pers[year].firstname = name;
        hist_pers[year].lastname = lastname;

    }
    void ChangeFirstName(int year, const std::string& first_name) {

        if (!CheckExistPerson(year))
        {
            hist_pers[year].firstname = first_name;
        }
    }
    void ChangeLastName(int year, const std::string& last_name) {
        if (!CheckExistPerson(year))
        {
            hist_pers[year].lastname = last_name;
        }
    }
    std::string GetFullName(int year) {
        if (CheckExistPerson(year))
        {
            return "No person";
        }

        std::string actually_first_name;
        std::string actually_last_name;
        for (const auto& i : hist_pers)
        {
            if (i.first > year)
            {
                break;
            }
            else if (i.second.firstname.size() != 0)
            {
                actually_first_name = i.second.firstname;
            }
            else if (i.second.lastname.size() != 0)
            {
                actually_last_name = i.second.lastname;
            }
        }
        if (actually_first_name.size() == 0 && actually_last_name.size() == 0)
        {
            return "Incognito";
        }
        else if (actually_first_name.size() == 0 && actually_last_name.size() != 0)
        {
            return actually_last_name + " with unknown first name";
        }
        else if (actually_first_name.size() != 0 && actually_last_name.size() == 0)
        {
            return actually_first_name + " with unknown last name";
        }
        else
        {
            return actually_first_name + " " + actually_last_name;
        }
    }

    std::string GetFullNameWithHistory(int year) {
        if (CheckExistPerson(year))
        {
            return "No person";
        }
        std::vector<std::string> h_f_n;
        std::vector<std::string> h_l_n;

        for (const auto& i : hist_pers)
        {
            if (i.first > year)
            {
                break;
            }
            if (i.second.firstname.size() != 0)
            {
                if (h_f_n.size() == 0)
                {
                    h_f_n.push_back(i.second.firstname);
                }
                if (i.second.firstname != h_f_n[h_f_n.size() - 1])
                {
                    h_f_n.push_back(i.second.firstname);
                }
            }
            if (i.second.lastname.size() != 0)
            {
                if (h_l_n.size() == 0)
                {
                    h_l_n.push_back(i.second.lastname);
                }
                else if (i.second.lastname != h_l_n[h_l_n.size() - 1])
                {
                    h_l_n.push_back(i.second.lastname);
                }
            }
        }

        std::string f_names;
        std::string l_names;

        if (h_f_n.size() > 1)
        {
            for (int i = 0; i < h_f_n.size(); i++)
            {
                if (i != h_f_n.size() - 1 && i != h_f_n.size() - 2)
                {
                    f_names = ", " + h_f_n[i] + f_names;
                }
                else if (i == h_f_n.size() - 2 && i != h_f_n.size() - 1)
                {
                    f_names = h_f_n[i] + f_names;
                }
                else
                {
                    break;
                }
            }
        }
        if (h_l_n.size() > 1)
        {
            for (int i = 0; i < h_l_n.size(); i++)
            {
                if (i != h_l_n.size() - 1 && i != h_l_n.size() - 2)
                {
                    l_names = ", " + h_l_n[i] + l_names;
                }
                else if (i == h_l_n.size() - 2 && i != h_l_n.size() - 1)
                {
                    l_names = h_l_n[i] + l_names;
                }
                else
                {
                    break;
                }
            }
        }
        if (h_l_n.size() > 1 && h_f_n.size() > 1)
        {
            return h_f_n[h_f_n.size() - 1] + " (" + f_names + ") " + h_l_n[h_l_n.size() - 1] + " (" + l_names + ") ";
        }
        else if (h_l_n.size() == 1 && h_f_n.size() == 1)
        {
            return h_f_n[h_f_n.size() - 1] + " " + h_l_n[h_l_n.size() - 1];
        }
        else if (h_l_n.size() == 1 && h_f_n.size() == 0)
        {
            return h_l_n[h_l_n.size() - 1] + " with unknow first name";
        }
        else if (h_l_n.size() > 1 && h_f_n.size() == 0)
        {
            return h_l_n[h_l_n.size() - 1] + " (" + l_names + ") " + " with unknow first name";
        }
        else if (h_l_n.size() == 0 && h_f_n.size() == 1)
        {
            return h_f_n[h_f_n.size() - 1] + " with unknow last name";
        }
        else if (h_l_n.size() == 0 && h_f_n.size() > 1)
        {
            return h_f_n[h_f_n.size() - 1] + " (" + f_names + ") " + " with unknow last name";
        }
        else if (h_l_n.size() == 1 && h_f_n.size() > 1)
        {
            return h_f_n[h_f_n.size() - 1] + " (" + f_names + ") " + h_l_n[h_l_n.size() - 1];
        }
        else if (h_l_n.size() > 1 && h_f_n.size() == 1)
        {
            return h_f_n[h_f_n.size() - 1] + " " + h_l_n[h_l_n.size() - 1] + " (" + l_names + ") ";
        }
        else
        {
            return "Incognito";
        }
    }
    bool CheckExistPerson(int year)
    {
        int low_year = 2022;
        for (const auto& i : hist_pers)
        {
            if (low_year > i.first)
            {
                low_year = i.first;
            }
        }
        if (low_year > year)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};




int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}