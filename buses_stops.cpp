

#include <iostream>
#include <string>
#include <map>
#include <vector>


void NewBus(std::map<std::string, std::vector<std::string>>& dict)
{
	std::string bus, stop;
	int stop_count;
	std::cin >> bus >> stop_count;
	for (int i = 0; i < stop_count; i++)
	{
		std::cin >> stop;
		dict[bus].push_back(stop);
	}
}


void BusesForStop(std::map<std::string, std::vector<std::string>>& dict)
{
	std::string stop;
	bool flag_for_error = true;
	std::cin >> stop;
	for (const auto& i : dict)
	{
		for (const auto k : i.second)
		{
			if (k == stop)
			{
				std::cout << i.first << " ";
				flag_for_error = false;
				break;
			}
		}
	}
	if (!flag_for_error)
	{
		std::cout << std::endl;
	}
	else
	{
		std::cout << "No stop" << std::endl;
	}
}


void StopsForBus(std::map<std::string, std::vector<std::string>>& dict)
{
	std::string bus;
	std::cin >> bus;
	if (dict.count(bus) != 0)
	{
		for (const auto& k : dict[bus])
		{
			bool flag_for_error = true;
			std::cout << "Stop " << k << ": ";
			for (const auto& i : dict)
			{
				if (i.first != bus)
				{
					for (const auto s : i.second)
					{
						if (s == k)
						{
							flag_for_error = false;
							std::cout << i.first << " ";
							break;
						}
					}
				}
			}
			if (!flag_for_error)
			{
				std::cout << std::endl;
			}
			else
			{
				std::cout << "no interchange" << std::endl;
			}
		}
	}
	else
	{
		std::cout << "No bus" << std::endl;
	}
}


void AllBuses(std::map<std::string, std::vector<std::string>>& dict)
{
	if (dict.size() != 0)
	{
		for (const auto& i : dict)
		{
			std::cout << "Bus " << i.first << ": ";
			for (const auto k : i.second)
			{
				std::cout << k << " ";
			}
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "No buses" << std::endl;
	}
}


int main()
{
	std::map<std::string, std::vector<std::string>> dictionary;
	std::string command;
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> command;
		if (command == "NEW_BUS")
		{
			NewBus(dictionary);
		}
		else if (command == "BUSES_FOR_STOP")
		{
			BusesForStop(dictionary);
		}
		else if (command == "STOPS_FOR_BUS")
		{
			StopsForBus(dictionary);
		}
		else if (command == "ALL_BUSES")
		{
			AllBuses(dictionary);
		}
	}

	return 0;
}


