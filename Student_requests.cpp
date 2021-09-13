#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct Student
{
    string first_name;
    string last_name;
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

int main() {
    int N;
    Student temp;
    vector<Student> st;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp.first_name >> temp.last_name >> temp.day >> temp.month >> temp.year;
        st.push_back(temp);
    }
    
    cin >> N;
    string get_request;
    int num_st;
    for (int i = 0; i < N; i++)
    {
        cin >> get_request >> num_st;
        --num_st;
        if (get_request == "name" && num_st <= st.size() && num_st >= 0)
        {
            cout << st[num_st].first_name << " " << st[num_st].last_name << "\n";
        }
        else if (get_request == "date" && num_st <= st.size() && num_st >= 0)
        {
            cout << st[num_st].day << "." << st[num_st].month << "." << st[num_st].year << "\n";
        }
        else
        {
            cout << "bad request" << endl;
        }
    }

    return 0;
}