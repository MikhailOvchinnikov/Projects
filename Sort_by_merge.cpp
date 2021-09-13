#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>

using namespace std;



template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if (range_end - range_begin < 2)
    {
        return;
    }
    vector<typename RandomIt::value_type> v(range_begin, range_end);
    auto middle = v.begin() + (v.end() - v.begin()) / 2;
    MergeSort(v.begin(), middle);
    MergeSort(middle, v.end());

    merge(v.begin(), middle, middle, v.end(), range_begin);
}

int main() {
    vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}



