#include "contact.hpp"

Contact::~Contact()
{
	this->index = "";
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->login = "";
	this->postal_address = "";
	this->email_address = "";
	this->phone_number = "";
	this->birthday_date = "";
	this->favorite_meal = "";
	this->underwear_color = "";
	this->darkest_secret = "";
}

Contact::Contact()
{
	std::string params[12] = {
			"index", "first_name", "last_name", "nickname", "login", "postal_address", "email_address", "phone_number",
			"birthday_date", "favorite_meal", "underwear_color", "darkest_secret"
	};
	this->index = "";
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->login = "";
	this->postal_address = "";
	this->email_address = "";
	this->phone_number = "";
	this->birthday_date = "";
	this->favorite_meal = "";
	this->underwear_color = "";
	this->darkest_secret = "";
	int i = 0;
	while (i < 12)
	{
		this->params[i] = params[i];
		i = i + 1;
	}
}

void Contact::init()
{
	this->num_params = 0;
}

std::string Contact::get_next_param()
{
	std::string temp = "";
	if(this->num_params < 12)
	{
		temp = this->params[this->num_params];
		this->num_params++;
	}
	return temp;
}

int Contact::set(std::string key, std::string value)
{
	if (value.empty())
		return 1;
	if (key == "index")
		this->index = value;
	else if (key == "first_name")
		this->first_name = value;
	else if (key == "last_name")
		this->last_name = value;
	else if (key == "nickname")
		this->nickname = value;
	else if (key == "login")
		this->login = value;
	else if (key == "postal_address")
		this->postal_address = value;
	else if (key == "email_address")
		this->email_address = value;
	else if (key == "phone_number")
		return this->set_phone(value);
	else if (key == "birthday_date")
		this->birthday_date = value;
	else if (key == "favorite_meal")
		this->favorite_meal = value;
	else if (key == "underwear_color")
		this->underwear_color = value;
	else if (key == "darkest_secret")
		this->darkest_secret = value;
	return 0;
}

int Contact::set_phone(std::string value)
{
	if (this->other_sym(value, " 1234567890()+-"))
	{
		std::cout << "Phone number can contain only numbers and ()/+/-, please do not use other symbols!" << std::endl;
		return 2;
	}
	this->phone_number = value;
	return 0;
}

int Contact::other_sym(std::string str, std::string templ)
{
	int step = 0;
	while (str[step])
	{
		int step2 = 0;
		while (templ[step2] && str[step] != templ[step2])
			step2++;
		if(templ[step2])
			step++;
		else
			return 1;
	}
	return 0;
}

std::string Contact::get(std::string key)
{
	if (key == "index")
		return this->index;
	else if (key == "first_name")
		return this->first_name;
	else if (key == "last_name")
		return this->last_name;
	else if (key == "nickname")
		return this->nickname;
	else if (key == "login")
		return this->login;
	else if (key == "postal_address")
		return this->postal_address;
	else if (key == "email_address")
		return this->email_address;
	else if (key == "phone_number")
		return this->phone_number;
	else if (key == "birthday_date")
		return this->birthday_date;
	else if (key == "favorite_meal")
		return this->favorite_meal;
	else if (key == "underwear_color")
		return this->underwear_color;
	else if (key == "darkest_secret")
		return this->darkest_secret;
	return "";
}

void Contact::display()
{
	std::string attr;
	this->init();
	attr = this->get_next_param();
	while (attr != "")
	{
		std::cout << attr << ": " << this->get(attr) << std::endl;
		attr = this->get_next_param();
	}
}