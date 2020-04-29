//Header file for class City
#ifndef CITY_H
#define CITY_H

#include <string>
#include <vector>
#include "Tourist_spots.h"
#include <iostream>
#include <fstream>
#include <iomanip>

class City : public Tourist_spots
{
private:
    std::vector<Tourist_spots> attractions;
    std::string population;
    std::string famous_cuisine;
    std::string description;
    std::string name;

public:
    void initialize_attractions();
    void set_population(std::string);
    void set_famous_cuisine(std::string);
    void set_name(std::string);
    std::vector<Tourist_spots> get_attractions() const;
    std::string get_population() const;
    std::string get_famous_cuisine() const;
    std::string get_name() const;
    void save_spot(City p)
    {
        std::ofstream output_file;
        output_file.open("final_list.txt", std::ios::app);
        output_file << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        output_file << "City: " << p.get_name() << std::endl << std::endl;
        output_file << "Weather: " << p.get_weather() << std::endl;
        output_file << "Population: " << p.get_population() << std::endl;
        output_file << "Famous Cuisine: " << p.get_famous_cuisine() << std::endl;
        output_file << "Description: " << std::endl << p.get_description() << std::endl;
        output_file << std::endl << "Attractions: " << std::endl;
        output_file << p.get_attractions();
        output_file << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        output_file << std::endl;
        output_file.close();
    }
    void set_description(std::string);
    std::string get_description() const;
    friend std::ostream& operator << (std::ostream& os, std::vector<City>vect)
    {
        for (auto p : vect)
        {
            os << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
            os << std::setw(100) << "City: " << p.get_name() << std::endl << std::endl;
            os << std::setw(100) << "Weather: " << p.get_weather() << std::endl;
            os << std::setw(100) << "Population: " << p.get_population() << std::endl;
            os << std::setw(100) << "Famous Cuisine: " << p.get_famous_cuisine() << std::endl;
            os << std::setw(100) << "Description: " << std::endl << p.get_description() << std::endl;
            os << std::setw(100) << std::endl << "Attractions: " << std::endl;
            os << p.get_attractions();
            os << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
            os << std::endl;
        }
        return os;
    }
};

#endif // !CITY_H
