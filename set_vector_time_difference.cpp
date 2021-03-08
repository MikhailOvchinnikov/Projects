// set_vector_time_difference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <vector>
#include <ctime>
#include <algorithm>

int main()
{
    std::set<int> s;
    std::vector<int> v;

    clock_t start, end;

    start = clock();

    for (int i = 0; i < 10000; i++)
    {
        if (i / 2 == 0)
        {
            s.insert(i);
        }
        else
        {
            s.insert(20000 - i);
        }
    }

    end = clock();
    std::cout << "set: " <<  end - start << std::endl;

    start = clock();

    for (int i = 0; i < 10000; i++)
    {
        if (i / 2 == 0)
        {
            v.push_back(i);
        }
        else
        {
            v.push_back(20000 - i);
        }
    }
    std::sort(v.begin(), v.end());
    end = clock();
    std::cout << "vector: " << end - start;
}

