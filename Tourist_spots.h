//Header file for class Tourist_spots
#ifndef TOURIST_SPOTS_H
#define TOURIST_SPOTS_H

#include <string>
#include "Tourist_spots.h"
#include <vector>
#include <iostream>
#include <iomanip>

class Tourist_spots
{
private:
    std::string name;
    std::string description;
    std::string weather;

    public:
    void set_name(std::string);
    virtual void set_description(std::string);
    void set_weather(std::string);
    std::string get_weather() const;
    virtual std::string get_description() const;
    std::string get_name() const;
    friend std::ostream& operator << (std::ostream& os, std::vector<Tourist_spots>vect)
    {
        for (auto p : vect)
        {
            os << std::setw(100) << "Name: " << p.get_name() << std::endl << std::endl;
            os << std::setw(100) << "Description: " << std::endl << p.get_description() << std::endl;
            os << "..................................................................................................................................................................................................................." << std::endl;
            os << std::endl;
        }
        return os;
    }

};
#endif // !TOURIST
