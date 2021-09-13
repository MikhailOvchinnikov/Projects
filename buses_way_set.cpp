

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>


void StopsForBuses(std::map<int, std::set<std::string>>& dict, int& way)
{
	int n;
	std::set<std::string> s;
	std::cin >> n;
	for (int k = 0; k < n; k++)
	{
		std::string line;
		std::cin >> line;
		s.insert(line);
	}

	bool flag_for_exist_way = false;
	int exist_way;

	for (const auto& i : dict)
	{
		if (i.second == s)
		{
			flag_for_exist_way = true;
			exist_way = i.first;
			break;
		}
	}
	if (!flag_for_exist_way)
	{
		dict[way] = s;
		std::cout << "New bus " << way << std::endl;
		way++;
	}
	else
	{
		std::cout << "Already exist for " << exist_way << std::endl;
	}
}


int main()
{
	int N;
	int n_way = 1;
	std::map<int, std::set<std::string>> dict;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		StopsForBuses(dict, n_way);
	}
	return 0;
}


