#include <iostream>
#include <vector>
#include <boost/multi_array.hpp>

template<typename T>

void fill_multi_array(boost::multi_array<T, 2>& ma, std::vector<std::vector<T>>& vect)
{
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			ma[i][k] = vect[i][k];
		}
	}
}

int main()
{
	typedef boost::multi_array<int, 2> mularr;
	mularr needed_mular(boost::extents[10][10]);
	std::vector<std::vector<int>> numbers;
	for (int i = 0; i < 10; i++)
	{
		std::vector<int> temp;
		for (int k = 0; k < 10; k++)
		{
			temp.push_back(rand() % 10);
		}
		numbers.push_back(temp);
	}
	fill_multi_array(needed_mular, numbers);

	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		for (int k = 0; k < 10; k++)
		{
			std::cout << needed_mular[i][k] << ' ';
		}
	}

}