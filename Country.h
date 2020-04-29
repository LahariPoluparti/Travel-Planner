//Header file for class Country
#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
#include <vector>
#include <iostream>
#include "Tourist_spots.h"
#include "Natural_spot.h"
#include "City.h"
#include <fstream>
#include <iomanip>

class Country {

private:
	std::string name;
	std::string price;
	std::string description;
	std::string native_language;
	static std::vector<std::string> country_list;
	std::string currency;
	int covid19_cases = 0;

public:
	std::vector<City> city_attractions;
	std::vector<Natural_spot> natural_attractions;
	void set_name(std::string);
	void set_price(std::string);
	void set_native_language(std::string);
	void set_description(std::string);
	void set_currency(std::string);
    static void add_to_country_list(std::string);
	void set_covid_19_cases(int);
	std::string get_name() const;
	std::string get_price() const;
	std::string get_native_language() const;
	std::string get_description() const;
	std::vector<City> get_city_attractions() const;
	std::vector<Natural_spot> get_natural_attractions() const;
	std::string get_currency() const;
	int get_covid_19_cases() const;
	void initialize_city_attractions();
	void initialize_natural_attractions();
	friend void print_concise_list(std::vector<Country> newlist);
	virtual void save_spot(Country p)
	{
		std::ofstream output_file;
		output_file.open("final_list.txt", std::ios::app);
		output_file << "Country: " << p.get_name() << std::endl << std::endl;
		output_file << "Estimated flight fares: " << p.get_price() << std::endl;
		output_file << "Native Language(s): " << p.get_native_language() << std::endl;
		output_file << "Currency: " << p.get_currency() << std::endl;
		output_file << "Covid19 Cases: " << p.get_covid_19_cases() << std::endl;
		output_file << "Description: " << std::endl << p.get_description() << std::endl;
		output_file << std::endl;
		output_file.close();
	}
	friend std::ostream& operator<<(std::ostream& os, const std::vector<Country> vect)
	{
		
		for (auto p : vect)
		{
			os << "==================================================================================================================================================================================================================" << std::endl;
			os << std::setw(100) << "Country: " << p.get_name() << std::endl <<  std::endl;
			os << std::setw(100) << "Estimated flight fares: " << p.get_price()  << std::endl;
			os << std::setw(100) << "Native Language(s): " << p.get_native_language()  << std::endl;
			os << std::setw(100) << "Currency: " << p.get_currency() << std::endl;
			os << std::setw(100) << "Covid19 Cases: " << p.get_covid_19_cases() <<  std::endl;
			os << std::setw(100) << "Description: " << std::endl;
			os << p.get_description()  << std::endl;
			os << "==================================================================================================================================================================================================================" << std::endl;
			
			os << std::endl;

		}
		return os;
	}

};

#endif // !COUNTRY_H

