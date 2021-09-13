
#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<typename T> T Sqr(T array);
template<typename Element> vector<Element> Pow(vector<Element>& v);
template<typename First, typename Second> map<First, Second> Pow(map<First, Second>& m);
template<typename First, typename Second> pair<First, Second> Pow(pair<First, Second>& p);
template<typename T> T Pow(T t);

template<typename Element>
vector<Element> Pow(vector<Element>& v)
{
    for (auto& i : v)
    {
        i *= i;
    }
    return v;
}

template<typename First, typename Second>
map<First, Second> Pow(map<First, Second>& m)
{
    for (auto& i : m)
    {
        i.second = Pow(i.second);
    }
    return m;
}

template<typename First, typename Second>
pair<First, Second> Pow(pair<First, Second>& p)
{
    p.first = Pow(p.first);
    p.second = Pow(p.second);
    return p;
}

template<typename T>
T Pow(T t)
{
    return t * t;
}



template<typename T>
T Sqr(T array)
{
    T temp_arr = array;
    temp_arr = Pow(temp_arr);
    return temp_arr;
}


int main()
{
    vector<int> v = { 1, 2, 3 };
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}
