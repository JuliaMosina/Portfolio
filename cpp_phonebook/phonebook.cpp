#include "phonebook.hpp"

Phonebook::Phonebook()
{
	this->number = 0;
	this->max_contact = 8;
}

Phonebook::~Phonebook()
{
}

int Phonebook::check_availability()
{
	if(this->number >= this->max_contact)
		return 1;
	else
		return 0;
}

int Phonebook::add_contact()
{
	if(this->check_availability())
	{
		std::cout << "Sorry, phonebook is full" << std::endl;
		return 1;
	}
	int i;
	std::string value;
	std::string attr;
	Contact attr_list;
	attr_list.init();
	attr = attr_list.get_next_param();
	while (attr != "")
	{
		if (attr != "index")
		{
			std::cout << "Please input " << attr << " of contact: " << std::endl;
			getline(std::cin, value);
			if ((i = attr_list.set(attr, value)))
			{
				if (i == 1)
					std::cout << "Sorry, void input is unacceptable" << std::endl;
			}
			else
				attr = attr_list.get_next_param();
		}
		else
		{
			attr_list.set(attr, std::to_string(this->number + 1));
			attr = attr_list.get_next_param();
		}
	}
	this->number++;
	return this->contact_edit(this->number - 1, attr_list);
}

int Phonebook::contact_edit(int number, Contact contact)
{
	if(number < 0 || number >= this->max_contact)
		return 1;
	this->contact[number] = contact;
	return 0;
}

int Phonebook::search_contact()
{
	this->put_contacts();
	if (this->number < 1)
	{
		std::cout << "Phonebook is empty at the moment" << std::endl;
		return 1;
	}
	this->input_index();
	return 0;
}

void Phonebook::put_contacts()
{
	Contact temp;
	std::string header_params[4] = {
			"index", "first_name", "last_name", "nickname"
	};
	int i = 0;
	std::cout << "|";
	while (i < 4)
	{
		this->put_substr(header_params[i]);
		std::cout << "|";
		i++;
	}
	std::cout << std::endl;
	if (this->number > 0)
	{
		int j = 0;
		while (j < this->number)
		{
			std::cout << "|";
			i = 0;
			while (i < 4)
			{
				temp = this->contact[j];
				this->put_substr(temp.get(header_params[i]));
				std::cout << "|";
				i++;
			}
			j++;
			std::cout << std::endl;
		}
	}
}

void Phonebook::put_substr(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else {
		std::cout << std::setw(10);
		std::cout << str;
	}
}

void Phonebook::input_index()
{
	int index;
	std::cout << "Please input index of the contact: " << std::endl;
	while (!(std::cin >> index) || !std::cin.good() || index < 1 || index > this->number)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "This index is unavailable, cause phonebook contains " << this->number << " records" << std::endl;
		std::cout << "Please input index of the contact: " << std::endl;
	}
	this->contact[index - 1].display();
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}