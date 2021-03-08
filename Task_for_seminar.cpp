// Task_for_seminar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <boost/circular_buffer.hpp>
#include <vector>
#include <string>
#include <ctime>
#include <typeinfo>
#include <windows.h>

struct Data_time
{
    std::string email;
    int dd;
    int  mm;
    int  yyyy;
    int  hh;
    int  min;
    int  ss;
};

void getStruct(tm* time, Data_time* st, std::string em)
{
    Data_time str = {};
    st->email = em;
    st->dd = time->tm_mday;
    st->mm = time->tm_mon;
    st->yyyy = time->tm_year;
    st->hh = time->tm_hour;
    st->min = time->tm_min;
    st->ss = time->tm_sec;

}

int main()
{
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    Data_time str[10];
    typedef boost::circular_buffer<struct Data_time> circular_buffer;
    circular_buffer cb{ 3 };

    getStruct(timeinfo, &str[0], "first@mail.ru");
    Sleep(2000);
    seconds = time(NULL);
    timeinfo = localtime(&seconds);
    getStruct(timeinfo, &str[1], "second@mail.ru");
    Sleep(1000);
    timeinfo = localtime(&seconds);
    getStruct(timeinfo, &str[2], "third@mail.ru");
    cb.push_back(str[0]);
    cb.push_back(str[1]);
    cb.push_back(str[2]);


    for (auto i : cb)
    {
        std::cout << i.email << "  " << i.dd << "." << i.mm << "." << i.yyyy + 1900 << "  " << i.hh << ":" << i.min << ":" << i.ss << std::endl;
    }
    Sleep(2000);
    seconds = time(NULL);
    timeinfo = localtime(&seconds);
    getStruct(timeinfo, &str[3], "fourth@mail.ru");
    cb.push_back(str[3]);

    std::cout << std::endl;

    for (auto i : cb)
    {
        std::cout << i.email << "  " << i.dd << "." << i.mm << "." << i.yyyy + 1900 << "  " << i.hh << ":" << i.min << ":" << i.ss << std::endl;
    }

    return 0;
}

