# Travel-Planner

This Object-oriented program lets the user create a travel plan or itenary with the places that they want to explore around the world. Because it is not possible to add all the countries around the world, I started with 15 countries with each 5 cities with their respective attractions. With this the user gets to explore the travel spots, get information about them, get number covid19 cases, and add spots to a user’s travel plan or itinerary.The program gives warnings to the user based on covid19 cases in a country when selecting it for the final itinerary. 

The program defines four classes:
  - A class that lists all the 15 countries
  - A class that lists famous tourist spots in those countries (thus the relation is ‘has a’, so composition is used between country and tourist spots)
  - A Tourist spot is broken into two subclasses
    - City (here the relationship is of ‘is a’ type, thus inheritance is used).
    - Natural spot (here the relationship is of ‘is a’ type, thus inheritance is used).

Functioning of the project: 
  The project will load list of data of Country type from text file and display available countries to the user. The user can browse countries and select which one he/she would like to visit. On selecting a country, its attractions will be revealed. The user can again browse through them based on their attributes and add attractions to their travel plan. After the user is done with selecting all the places, the program will display and store the final itinerary which can be used a travel plan/guide. Moreover, the program will ask if the user wants to save the itinerary. If the user says yes, the itinerary will be saved into a text file.
  
OVERVIEW OF CLASSES:
1. Country: This class contains 9 data members and 20 member functions. This class will define a country and will have members which define the attributes (related to travel) for a country (super class).

2. Tourist_spots: This class contains 3 data members and 7 member functions. This class will define attributes of a tourist spot (composed from the class country)

3. City: This class contains 5 data members and 12 member functions. This class inherits from Tourist_spot, will define a city and show the user its tourist attraction

4. Natural_spot: This class contains 4 data members and 10 member functions. This class inherits from Tourist_spots, will define geographic attractions of a country




