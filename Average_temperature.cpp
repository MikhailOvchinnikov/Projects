#include <iostream>
#include <vector>

using namespace std;



int main() {
	int N;
	vector<int> temp;
	cin >> N;

	int t;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		temp.push_back(t);
		sum += t;
	}
	sum = sum / static_cast<int>(temp.size());
	vector<int> day_above_avg;
	int num_days = 0;
	for (int i = 0; i < static_cast<int>(temp.size()); i++)
	{
		if (temp[i] > sum)
		{
			day_above_avg.push_back(i);
			num_days++;
		}
	}
	cout << num_days << endl;
	for (const auto& i : day_above_avg)
	{
		cout << i << ' ';
	}
	
	return 0;
}
