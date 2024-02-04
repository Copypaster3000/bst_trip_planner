//trip_entry.cpp
//This file holds the class definitions for trip entry. These functions are used to hold and do things with the details
//of an individual trip. The details of each trip are stored in their own instance of this class which is initialized in
//each node 

#include <cstring>
#include "trip_entry.h"
using namespace std;

trip_entry::trip_entry(void)
{
	name = nullptr;
	location = nullptr;
	attraction = nullptr;
	when = nullptr;
	travel = nullptr;
	climate = nullptr;
}



trip_entry::~trip_entry(void)
{

	delete[] name; //Name of location
	delete[] location; //State and/or country
	delete[] attraction; //Best thing to do there
	delete[] when; //Best time of the year to go
	delete[] travel; //How to travel there
	delete[] climate; //The climate of the area
}



//Pass in struct w/ trip info, sets private members w/ info dynamically
void trip_entry::set(front_trip& trip)
{
	if (name) //If trip's ptr's aren't null, deletes them before setting them again
	{
		delete[] name;
		delete[] location;
		delete[] attraction; 
		delete[] when; 
		delete[] travel;
		delete[] climate; 
	}

	set_member_dynamic(trip.name, name);
	set_member_dynamic(trip.location, location);
	set_member_dynamic(trip.attraction, attraction);
	set_member_dynamic(trip.when, when);
	set_member_dynamic(trip.travel, travel);
	set_member_dynamic(trip.climate, climate);

	return;
}



//Private ADT member function only used inside other ADT functions
//Takes in temporary struct member and node member pointer to set pointer to dynamically allocated array 
void trip_entry::set_member_dynamic(char temp_struct_member[], char*& actual_member)
{
    actual_member = new char[strlen(temp_struct_member) + 1]; //Sets struct member pointer to perfect size array
    strcpy(actual_member, temp_struct_member); //Copies user input to dynamically allocated array

    return;
}



//Displays trip details to user
void trip_entry::display(void)
{
	cout << "Name of the location: " << name << endl;
	cout << "State, Country: " << location << endl;
	cout << "Attraction: " << attraction << endl;
	cout << "Best time to travel: " << when << endl;
	cout << "How to get there: " << travel << endl;
	cout << "Climate (or other detail): " << climate << endl;
	cout << endl;

	return;
}



//Returns 1 if name passed in matches classes name member, 0 if not
int trip_entry::name_match(char check[])
{
	if (!strcmp(check, name)) return 1;

	return 0;
}
	


//Retruns 1 if when passed in matches class member when
int trip_entry::when_match(char check[])
{
	if (!strcmp(check, when)) return 1;

	return 0;
}



//Sets struct passed in with trip details
void trip_entry::copy_to(front_trip& trip_info)
{
	strcpy(trip_info.name, name);
	strcpy(trip_info.location, location);
	strcpy(trip_info.attraction, attraction);
	strcpy(trip_info.when, when);
	strcpy(trip_info.travel, travel);
	strcpy(trip_info.climate, climate);

	return;
}


//Pass in key to trip being added and key of current node, returns 0 if alphabetically less than current node or 1 if greater than or equal to
int trip_entry::compare(char adding[])
{
	if (strcmp(adding, name) < 0) return 0;

	return 1;
}
