//trip_entry.h
//This is the header file for the class trip_entry which holds and edits and stuff details
//for the trip it represents

#include <cstring>
#include <cctype>
#include <iostream>
#include "front_trip.h"

class trip_entry
{
	public:
		trip_entry(void);
		~trip_entry(void);
		void set(front_trip& trip); //Pass in struct w/ trip info, sets private members w/ info dynamically
		void display(void); //Displays trip details to user
		int name_match(char check[]); //Returns 1 if name passed in is a match, 0 if not
		int when_match(char when[]); //Returns 1 if best time to travel passed in is a match, 0 if not
		void copy_to(front_trip& trip_info); //Copies trip details to struct passed in
		int compare(char adding[]); //Returns 0 if adding is less than name alphabetically and 1 if not
	
	private:
		void set_member_dynamic(char temp_struct_member[], char*& actual_member); //Uses first arg to set second arg to dynamically allocated array
		char* name; //Name of location
		char* location; //State and/or country
		char* attraction; //Best thing to do there
		char* when; //Best time of the year to go
		char* travel; //How to travel there
		char* climate; //The climate of the area
};
