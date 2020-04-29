//Header file for class Natural_spot
#ifndef NATURAL_SPOT_H
#define NATURAL_SPOT_H

#include <string>
#include <iostream>
#include <vector>
#include "Tourist_spots.h"
#include <fstream>
#include <iomanip>

class Natural_spot : public Tourist_spots
{
private:
    std::string activities;
    std::string type;
    std::string description;
    std::string name;

public:
    void set_activities(std::string);
    void set_name(std::string);
    void set_type(std::string);
    std::string get_activities() const;
    std::string get_type() const;
    void save_spot(Natural_spot p)
    {
        std::ofstream os;
        os.open("final_list.txt", std::ios::app);
        os << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        os << "Natural spot: " << p.get_name() << std::endl << std::endl;
        os << "Weather: " << p.get_weather() << std::endl;
        os << "Type: " << p.get_type() << std::endl;
        os << "Activities: " << p.get_activities() << std::endl;
        os << "Description: " << std::endl << p.get_description() << std::endl;
        os << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        os << std::endl;
        os.close();
    }
    void set_description(std::string);
    std::string get_description() const;
    std::string get_name() const;
    friend std::ostream& operator << (std::ostream& os, std::vector<Natural_spot> vect)
    {
        for (auto p : vect)
        {
            os << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
            os << std::setw(100) << "Natural spot: " << p.get_name() << std::endl << std::endl;
            os << std::setw(100) << "Weather: " << p.get_weather() << std::endl;
            os << std::setw(100) << "Type: " << p.get_type() << std::endl;
            os << std::setw(100) << "Activities: " << p.get_activities() << std::endl;
            os << std::setw(100) << "Description: " << std::endl << p.get_description() << std::endl;
            os << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
            os << std::endl;
        }
        return os;
    }

};
#endif // !NATURAL_SPOT_H
