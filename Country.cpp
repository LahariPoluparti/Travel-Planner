//Implementation file for the class Country
#include "Country.h"
#include "City.h"
#include "Natural_spot.h"
#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> Country::country_list;
void Country::set_name(std::string name)
{
	this->name = name;
}
void Country::set_price(std::string price)
{
	this->price = price;
}
void Country::set_native_language(std::string lang)
{
	native_language = lang;
}
void Country::set_description(std::string descr)
{
	description = descr;
}
void Country::set_currency(std::string currency)
{
	this->currency = currency;
}
void Country::add_to_country_list(std::string new_country)
{
	country_list.push_back(new_country);
}
void Country::set_covid_19_cases(int cases)
{
	covid19_cases = cases;
}
std::string Country::get_name() const
{
	return name;
}
std::string Country::get_price() const
{
	return price;
}
std::string Country::get_native_language() const
{
	return native_language;
}
std::string Country::get_description() const
{
	return description;
}
std::vector<City> Country::get_city_attractions() const
{
	return city_attractions;
}
std::vector<Natural_spot> Country::get_natural_attractions() const
{
	return natural_attractions;
}
std::string Country::get_currency() const
{
	return currency;
}
int Country::get_covid_19_cases() const
{
	return covid19_cases;
}
void Country::initialize_city_attractions()
{
	city_attractions.clear();
	std::ifstream input_file;
	input_file.open(name + "-cities.txt");

	if (input_file)
	{
		while (!input_file.eof())
		{
			City new_city;
			std::string name;
			getline(input_file, name, '\t');
			new_city.set_name(name);
			std::string pop;
			getline(input_file, pop, '\t');
			new_city.set_population(pop);
			std::string food;
			getline(input_file, food, '\t');
			new_city.set_famous_cuisine(food);
			std::string descr;
			getline(input_file, descr, '\t');
			new_city.set_description(descr);
			std::string weather;
			getline(input_file, weather, '\n');
			new_city.set_weather(weather);
			new_city.initialize_attractions();
			city_attractions.push_back(new_city);

		}
	}
	input_file.close();

}
void Country::initialize_natural_attractions()
{
	natural_attractions.clear();
	std::ifstream input_file;
	input_file.open(name + "-natural.txt");

	if (input_file)
	{
		while (!input_file.eof())
		{
			Natural_spot new_spot;
			std::string name;
			getline(input_file, name, '\t');
			new_spot.set_name(name);
			std::string act;
			getline(input_file, act, '\t');
			new_spot.set_activities(act);
			std::string type;
			getline(input_file, type, '\t');
			new_spot.set_type(type);
			std::string descr;
			getline(input_file, descr, '\t');
			new_spot.set_description(descr);
			std::string weather;
			getline(input_file, weather, '\n');
			new_spot.set_weather(weather);
			natural_attractions.push_back(new_spot);

		}
	}
	input_file.close();
}
