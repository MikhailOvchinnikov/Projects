

#include <iostream>
#include <string>
#include <map>
#include <vector>


void InputStopsAndWays(std::map<std::vector<std::string>, int>& dict, int& count)
{
	int n;
	std::string stop;
	std::vector<std::string> vec;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> stop;
		vec.push_back(stop);
	}

	bool flag = true;
	int way;

	for (const auto& i : dict)
	{
		if (i.first == vec)
		{
			flag = false;
			way = i.second;
			break;
		}
	}
	if (flag)
	{
		dict[vec] = count;
		std::cout << "New bus " << count << std::endl;
		count++;
	}
	else
	{
		std::cout << "Already exists for " << way << std::endl;
	}
}


int main()
{
	int counter = 1;
	std::map<std::vector<std::string>, int> dictionary;
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		InputStopsAndWays(dictionary, counter);
	}

	return 0;
}


