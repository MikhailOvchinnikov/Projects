

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>


void Add(std::map<std::string, std::set<std::string>>& dict)
{
	std::string word1, word2;
	std::cin >> word1 >> word2;
	dict[word1].insert(word2);
	dict[word2].insert(word1);
}


void Count(std::map<std::string, std::set<std::string>>& dict)
{
	std::string word;
	std::cin >> word;
	std::cout << dict[word].size() << std::endl;
}


void Check(std::map<std::string, std::set<std::string>>& dict)
{
	std::string word1, word2;
	std::cin >> word1 >> word2;
	if (dict[word1].count(word2) != 0 || dict[word2].count(word1) != 0)
	{
		std::cout << "YES" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}
}


int main()
{
	int N;
	std::string command;
	std::map<std::string, std::set<std::string>> dictionary;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> command;
		if (command == "ADD")
		{
			Add(dictionary);
		}
		else if (command == "COUNT")
		{
			Count(dictionary);
		}
		else if (command == "CHECK")
		{
			Check(dictionary);
		}
	}
	return 0;
}


