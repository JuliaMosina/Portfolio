#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "contact.hpp"

class Phonebook {
public:
	Phonebook();
	~Phonebook();
	int check_availability();
	int add_contact();
	int contact_edit(int number, Contact contact);
	int search_contact();
	void put_contacts();
	void put_substr(std::string str);
	void input_index();

private:
	int number;
	int max_contact;
	Contact contact[8];
};

#endif