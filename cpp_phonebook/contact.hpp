#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact {
public:
	Contact();
	~Contact();
	void init();
	std::string get_next_param();
	int set(std::string key, std::string value);
	int set_phone(std::string value);
	int other_sym(std::string str, std::string templ);
	std::string get(std::string key);
	void display();

private:
	int num_params;
	std::string index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birthday_date;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;
	std::string params[12];
};

#endif