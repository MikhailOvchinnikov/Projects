#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };
    int a;
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cin >> a;
        vec.push_back(a);
    }
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::random_shuffle(vec.begin(), vec.end());
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    for (std::vector<int>::iterator i = vec.begin(); i != vec.end();)
    {
        int count = 0;
        for (auto b : vec)
        {
            if ((*i) == b)
                count++;

        }
        if (count >= 2)
        {
            i = vec.erase(i);
        }
        else
        {
            i++;
        }
    }
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    int count = 0;

    for (auto b : vec)
    {
        if (b % 2 != 0)
        {
            count++;
        }
    }
    std::cout << count << std::endl;

    std::vector<int>::iterator it;
    it = std::min_element(vec.begin(), vec.end());
    std::cout << "min: " << (*it) << std::endl;
    it = std::max_element(vec.begin(), vec.end());
    std::cout << "max: " << (*it) << std::endl;

    for (auto b : vec)
    {
        int count = 0;
        for (int i = b; i > 0; i--)
        {
            if (b % i == 0)
            {
                count++;
            }
        }
        if (count == 2)
        {
            std::cout << "simple figure: " << b << std::endl;
            break;
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = vec[i] * vec[i];
    }
    std::cout << "Squared array: ";
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> vec_2(vec.size());
    for (int i = 0; i < vec_2.size();i++)
    {
        vec_2[i] = rand() - 32767 / 2;
    }
    
    std::cout << "New vector: ";
    copy(vec_2.begin(), vec_2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    auto sum = std::accumulate(vec_2.begin(), vec_2.end(), 0);
    std::cout << "Sum elements of new vector: " << sum << std::endl;
    
    for (int i = 0; i < 5; i++)
    {
        vec_2[i] = 1;
    }
    copy(vec_2.begin(), vec_2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> vec_3(vec_2.size());
    for (int i = 0; i < vec_2.size(); i++)
    {
        vec_3[i] = vec[i] - vec_2[i];
    }

    std::cout << "Third new vector: ";
    copy(vec_3.begin(), vec_3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::replace_if(vec_3.begin(), vec_3.end(), [](int x) { return x < 0; }, 0);

    copy(vec_3.begin(), vec_3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    for (std::vector<int>::iterator it = vec_3.begin(); it != vec_3.end();)
    {
        if ((*it) == 0)
        {
            it = vec_3.erase(it);
        }
        else
        {
            it++;
        }
    }
    std::cout << "Without zeros: ";
    copy(vec_3.begin(), vec_3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    reverse(vec_3.begin(), vec_3.end());

    std::cout << "Reverse: ";
    copy(vec_3.begin(), vec_3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    {
        std::vector<int> t_vec;
        t_vec = vec_3;
        std::cout << "Three the biggest figure: ";
        for (int i = 0; i < 3; i++)
        {
            it = std::max_element(t_vec.begin(), t_vec.end());
            std::cout << (*it) << " ";
            it = t_vec.erase(it);
        }
    }
    std::cout << std::endl << "Sorted array: ";
    sort(vec_3.begin(), vec_3.end());
    copy(vec_3.begin(), vec_3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> vec_4;
    vec_4.insert(vec_4.end(), vec.begin(), vec.end());
    vec_4.insert(vec_4.end(), vec_2.begin(), vec_2.end());
    std::cout << "Merged array: ";
    copy(vec_4.begin(), vec_4.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;



}

