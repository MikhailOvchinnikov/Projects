#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border)
{
	vector<T> new_elements;
	auto it = find_if(elements.begin(), elements.end(), [border](const T& x) {return x > border; });
	for (; it != elements.end(); it++)
	{
		new_elements.push_back(*it);
	}
	return new_elements;
}

int main() {
	for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
		cout << x << " ";
	}
	cout << endl;

	string to_find = "Python";
	cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
	return 0;
}