/*********************************************************************************************************************
*					Project Name: Travel Planner																	 *
*					Author(s): Param Chokshi, Kejvi Cupa, Lahari Poluparti											 *
*					Decription: The program helps the user a make a travel plan by browsing different attractions	 *
*					across various countries, and saving them in a text file.										 *
**********************************************************************************************************************/
#include "City.h"
#include "Country.h"
#include "Natural_spot.h"
#include "Tourist_spots.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "__________________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << endl;
	cout << setw(105) << "Travel Planner" << endl;
	cout << "__________________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << endl;
	cout << setw(105) << "List of Countries" << endl;
	cout << endl;
    vector<Country> list;
    ifstream input;
    input.open("country.txt");

	

	if (input)
	{
		
		while (!input.eof())
		{
			Country new_count;
			string name;
			getline(input, name, '\t');
			new_count.set_name(name);
			string curr;
			getline(input, curr, '\t');
			new_count.set_currency(curr);
			string lang;
			getline(input, lang, '\t');
			new_count.set_native_language(lang);
			string descr;
			getline(input, descr, '\t');
			new_count.set_description(descr);
			string covid;
			getline(input, covid, '\t');
			int cases = stoi(covid);
			new_count.set_covid_19_cases(cases);
			string price1;
			getline(input, price1, '\n');
			new_count.set_price(price1);
			Country::add_to_country_list(name);
			list.push_back(new_count);
		}
	}
	input.close();
	cout << list << endl << endl;
	char sorv = ' ';
	while (sorv != 'X')
	{
		cout << endl << "S: Save Spots to Itinerary " << endl << "V: View Countries" << endl << "X: Exit" << endl;

		cout << "Enter (S,V, or X): ";
		cin >> sorv;
		sorv = toupper(sorv);
		cin.ignore(1000, '\n');

		while (sorv != 'S' && sorv != 'V' && sorv != 'X')
		{
			cout << "Invaild Input, Renter (S,V, or X): ";
			cin >> sorv;
			sorv = toupper(sorv);
			cin.ignore(1000, '\n');
		}

		if (sorv == 'S')
		{
			print_concise_list(list);
			int validate = 0;
			do
			{
				string country1;
				cout << endl << "Enter the name of the country (from the list) you would like to go to: ";
				getline(cin, country1);
				for (auto p : list)
				{

					if (p.get_name() == country1)
					{
						validate++;
						p.initialize_city_attractions();
						p.initialize_natural_attractions();
						p.save_spot(p);
						cout << "Country saved to your itinerary...." << endl << endl;
						cout << p.city_attractions << endl;
						cout << p.natural_attractions << endl;


						char response2 = 'Y';

						while (response2 == 'Y')
						{
							int check = 0;
							while (check == 0)
							{
								string resp_name;
								cout << endl << "Enter name of a attraction: ";
								getline(cin, resp_name);
								for (auto c : p.city_attractions)
								{
									if (resp_name == c.get_name())
									{
										c.save_spot(c);
										cout << "City saved to your itinerary...." << endl << endl;
										check++;
									}
								}

								for (auto n : p.natural_attractions)
								{
									if (resp_name == n.get_name())
									{
										n.save_spot(n);
										cout << "Natural Spot saved to your itinerary...." << endl << endl;
										check++;
									}
								}

								if (check == 0)
								{
									cout << "Invalid name. Try again. " << endl;
								}
							}

							cout << endl << "Would you like to enter one more tourist spot? (Y/N): ";
							cin >> response2;
							response2 = toupper(response2);
							cin.ignore(1000, '\n');
						}

					}

				}
			} while (validate == 0);
			
			
		}



		if (sorv == 'V')
		{
			int flag = 0;
			do
			{
				cout << endl;
				print_concise_list(list);
				cout << endl;
				string response_country;
				cout << "Enter a valid country: ";
				getline(cin, response_country);

				for (auto p : list)
				{
					if (p.get_name() == response_country)
					{
						flag = 1;
						p.initialize_city_attractions();
						p.initialize_natural_attractions();

						cout << p.city_attractions << endl;
						cout << p.natural_attractions << endl;
					}
				}
			} while (flag == 0);
			
		}
	}
	
	cout << endl << "Your itinerary is stored in final_list.txt" << endl;
	char final_resp = ' ';
	cout << "Do want to see a preview of the list? (Enter Y for yes): ";
	cin >> final_resp;
	cin.ignore(1000, '\n');
	final_resp = toupper(final_resp);
	if (final_resp == 'Y')
	{
		ifstream input;
		input.open("final_list.txt");
		cout << endl;
		if (input)
		{
			while (!input.eof())
			{
				string buffer;
				getline(input, buffer);
				cout << buffer << endl;
			}
		}

		input.close();

	}
	

	return 0;

}

void print_concise_list(std::vector<Country> newlist)
{
	int i = 0;
	
	for (auto b : Country::country_list)
	{
		cout << b << ": Alert (refer covid19 cases before visiting) - " << newlist[i].get_covid_19_cases() << endl;
		i++;
	}

}