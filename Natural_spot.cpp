//Implementation file for the class Natural_spot
#include "Natural_spot.h"
#include <string>
#include <iostream>

void Natural_spot::set_activities(std::string act)
{
	activities = act;
}

void Natural_spot::set_name(std::string name)
{
	this->name = name;
}

void Natural_spot::set_type(std::string type)
{
	this->type = type;
}
std::string Natural_spot::get_activities() const
{
	return activities;
}
std::string Natural_spot::get_type() const
{
	return type;
}

void Natural_spot::set_description(std::string descr)
{
	description = descr;
}
std::string Natural_spot::get_description() const
{
	return description;
}

std::string Natural_spot::get_name() const
{
	return name;
}