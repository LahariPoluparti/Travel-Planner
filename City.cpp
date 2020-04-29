//Implementation file for the class City
#include "City.h"
#include "Tourist_spots.h"
#include <string>
#include <vector>
#include <iostream>

void City::initialize_attractions()
{
	attractions.clear();
	std::ifstream input_file;
	input_file.open(name + ".txt");

	if (input_file)
	{
		while (!input_file.eof())
		{
			Tourist_spots new_spot;
			std::string descr;
			getline(input_file, descr, '\t');
			new_spot.set_description(descr);
			std::string name1;
			getline(input_file, name1, '\n');
			new_spot.set_name(name1);
			attractions.push_back(new_spot);

		}
	}
	input_file.close();
}
void City::set_population(std::string pop)
{
	population = pop;
}
void City::set_famous_cuisine(std::string cuisine)
{
	famous_cuisine = cuisine;
}

void City::set_name(std::string name)
{
	this->name = name;
}
std::vector<Tourist_spots> City::get_attractions() const
{
	return attractions;
}
std::string City::get_population() const
{
	return population;
}
std::string City::get_famous_cuisine() const
{
	return famous_cuisine;
}
void City::set_description(std::string descr)
{
	description = descr;
}
std::string City::get_description() const
{
	return description;
}

std::string City::get_name() const
{
	return name;
}