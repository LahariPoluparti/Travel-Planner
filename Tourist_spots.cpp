//Implementation file for the class Tourist_spots
#include "Tourist_spots.h"
#include <string>


void Tourist_spots::set_name(std::string name)
{
	this->name = name;
}
void Tourist_spots::set_description(std::string descr)
{
	description = descr;
}
void Tourist_spots::set_weather(std::string weather)
{
	this->weather = weather;
}
std::string Tourist_spots::get_weather() const
{
	return weather;
}
std::string Tourist_spots::get_description() const
{
	return description;
}
std::string Tourist_spots::get_name() const
{
	return name;
}