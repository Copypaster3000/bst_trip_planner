//front.cpp
//Drake Wheeler
//This file holds the definitions for the front class. The front class is used to test the tree class functions.

#include <iostream>
#include "front.h"
using namespace std;

front::front(void)
{}



front::~front(void)
{}



//Welcomes user, explains program
void front::welcome(void)
{
	cout << "\nHello. This program helps you keep track of trip ideas you have." << endl;
	cout << "Use the menu below." << endl;

	return;
}



//Displays menu option to user and returns user's choice
int front::menu(void)
{
	cout << "\nSelect an option from the menu below" << endl;
	cout << "1) Add a new trip" << endl;
	cout << "2) Add external data file \"travel.txt\"" << endl;
	cout << "3) Display all trips in alphabetical order" << endl;
	cout << "4) Remove a trip based on name of the location" << endl;
	cout << "5) Retrieve trip's information based on name of the location (and then display it)" << endl;
	cout << "6) Display all trips that have the same best time to travel there" << endl;
	cout << "7) Display the number of data items and height of the binary search tree" << endl;
	cout << "8) End program\n" << endl;

	return get_integer();
}



void front::option_one(void)
{
	front_trip trip_info;
	
	cout << "\nPlease type everything in lower case." << endl;

	get_front_trip(trip_info);

	if (trips.insert(trip_info))
		cout << "\nTrip successfully added." << endl;
	else
		cout << "\nA trip with the location name is already logged." << endl;

	return;		
}



void front::option_two(void)
{
	if (trips.load_file("travels.txt"))
		cout << "\nFile successfully added." << endl;
	else
		cout << "\nUnable to access external data file." << endl;
	
	return;
}


void front::option_three(void)
{
	if (!trips.abc_display())
		cout << "\nThere are not trips to display." << endl;

	return;
}



void front::option_four(void)
{
	char name[MAX];

	cout << "\nType in the name of the trip that you would like to remove: ";
	cin.get(name, MAX, '\n');
	cin.ignore(MAX, '\n');

	if (!trips.remove(name))
		cout << "\nThere is no trip that matches that name to be removed." << endl;
	else
		cout << "\nThat trip has been removed." << endl;

	return;
}


void front::option_five(void)
{
	char name[MAX]; 
	front_trip trip_info;

	cout << "\nType in the name of the location of the trip you would like to see: ";
	cin.get(name, MAX, '\n');
	cin.ignore(MAX, '\n');

	if (!trips.retrieve(name, trip_info))
		cout << "\nThere is no trip that matches that name to retrieve." << endl;
	else
	{
		cout << "\nName of the location: " << trip_info.name << endl;
		cout << "State, Country: " << trip_info.location << endl;
		cout << "Best attractions: " << trip_info.attraction << endl;
		cout << "Best time to travel: " << trip_info.when << endl;
		cout << "How to get there: " << trip_info.travel << endl;
		cout << "Climate (or other detail): " << trip_info.climate << endl;
	}

	return;
}



void front::option_six(void)
{
	char when[MAX];
	
	cout << "\nType in the best time to travel of the trips you would like to see: ";
	cin.get(when, MAX, '\n');
	cin.ignore(MAX, '\n');

	if (!trips.display_by_when(when))
		cout << "There are no trips that match that best time to travel." << endl;

	return;
}



void front::option_seven(void)
{
	if (!trips.display_bst_data())
		cout << "\nError displaying data." << endl;
	
	return;
}



void front::get_front_trip(front_trip& trip_info)
{
		cout << endl;
		get_char_array("the name of the location", trip_info.name);
		get_char_array("the State and/or Country", trip_info.location);
		get_char_array("the best things to do there", trip_info.attraction);
		get_char_array("the best time of the year to go", trip_info.when);
		get_char_array("how to travel there", trip_info.travel);
		get_char_array("the climate of the area", trip_info.climate);

		return;
}



int front::get_integer(void)
{
    int num{0};

    cout << "Enter integer here: ";
    cin >> num;
    while (!cin || cin.peek() != '\n') // If user doesn't enter an integer...
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid entry, enter and integer: ";
        cin >> num; // Prompts for and gets input again
    }
    cin.ignore(100, '\n');

    return num;
}



// Gets struct member detail from user, first argument is prompt for detail, second arg is where user input will be stored (temp struct member)
void front::get_char_array(char member_name[], char actual_temp_member[])
{
    cout << "Type in " << member_name << ": "; //Prompts user for detail
    cin.get(actual_temp_member, MAX, '\n'); //Stores user input in temporary array
    cin.ignore(100, '\n'); //Clears input stream
    cout << "You entered \"" << actual_temp_member << "\"." << endl; //Echos to user what they entered

    return;
}
