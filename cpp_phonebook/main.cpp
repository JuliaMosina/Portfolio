#include "phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string command;
	int exit = 0;

	while (!exit)
	{
		if(!phonebook.check_availability())
			std::cout << "Please choose and enter one of the following options: ADD SEARCH EXIT" << std::endl;
		else
			std::cout << "Please choose and enter one of the following options: SEARCH EXIT" << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			if(!phonebook.add_contact())
				std::cout << "Contact was successfully created" << std::endl;
		}
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			exit = 1;
		else
			std::cout << "Sorry, this option is unacceptable" << std::endl;
	}
	return 0;
}