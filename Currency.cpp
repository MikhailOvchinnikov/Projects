

#include <iostream>
#include <vector>
#include <locale>
#include <sstream>
#include <iomanip>
#include <Windows.h>

double EU = 89.48;

void show_currency_symbol(const std::string& locale_name)
{
	std::cout << std::use_facet < std::moneypunct < char, false > >(std::locale(locale_name)).curr_symbol() << std::endl;
}

int main()
{
	SetConsoleCP(CP_UTF8); 
	SetConsoleOutputCP(CP_UTF8);
	std::cout << "Enter the amount in EUR: ";
	double value;
	double conv_value;
	std::cin >> value;
	std::cout<< std::endl << "You entered: " << std::showbase << std::put_money(value, false) << " ";
	show_currency_symbol("de_DE.utf8");
	std::cout << std::endl;
	conv_value = value * EU;
	std::cout << "converted to RU: " << std::showbase << std::get_money(conv_value, false) << " ";
	show_currency_symbol("ru_RU.utf8");
}


