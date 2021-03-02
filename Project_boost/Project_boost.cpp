// Project_boost.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <memory>

class BankCell
{
public:
	BankCell()
	{
		std::cout << "bank cell created" << std::endl;
	}

	~BankCell()
	{
		std::cout << "bank cell deleted" << std::endl;
	}
};

class Human
{
	std::string h_name;
	std::shared_ptr<BankCell> ptr;
public:
	Human(std::string name, std::shared_ptr<BankCell> bc): h_name(name)
	{
		ptr =  bc;
		std::cout << h_name << " was born" << std::endl;
	}

	~Human()
	{
		std::cout << h_name << " died" << std::endl;
	}

	std::shared_ptr<BankCell> getBankCell()
	{
		return ptr;
	}
		
	void setBankCell()
	{
		ptr = std::shared_ptr<BankCell>(new BankCell);
	}
};



int main()
{
	std::shared_ptr<BankCell> ptr;
	Human* hum1 = new Human("Anton", ptr);
	hum1->setBankCell();
	Human* hum2 = new Human("Anton", hum1->getBankCell());
	delete hum1;
	delete hum2;
	Human* hum3 = new Human("Vasia", ptr);
	hum3->setBankCell();
	delete hum3;

}