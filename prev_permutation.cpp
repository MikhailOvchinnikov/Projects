#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>

using namespace std;



void Permutation(int number)
{
    vector<int> p;
    int fact = 1;
    for (int i = 1; i <= number; i++)
    {
        p.push_back(i);
        fact *= i;
    }
    reverse(p.begin(), p.end());
    for (int i = 1; i <= fact; i++)
    {
        for (const auto& k : p)
        {
            cout << k << ' ';
        }
        prev_permutation(p.begin(), p.end());
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    Permutation(n);
    return 0;
}