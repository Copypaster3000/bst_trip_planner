//*************************************************************************************************
//4prog.cpp                                                                                       * 
//Drake Wheeler                                                                                   * 
//Karla Fant                                                                                      *
//CS163                                                                                           * 
//Program 4                                                                                       * 
//5/21/2023                                                                                       * 
//This file holds the main function which organizes and calls all the other functions for the     * 
//program. This program utilizes a binary search tree to allow the user to store and edit trip    * 
//ideas.                                                                                          *
//*************************************************************************************************

#include "front.h"
#include "iostream"
using namespace std;


int main()
{
	front tester; //Instance of front class to call functions
	int choice {0};

	tester.welcome(); //Welcomes user, explains program

	do 
	{
		choice = tester.menu(); //Display menu options to user and returns their choice as an int

		if (choice == 1) tester.option_one();

		if (choice == 2) tester.option_two();

		if (choice == 3) tester.option_three();

		if (choice == 4) tester.option_four();

		if (choice == 5) tester.option_five();

		if (choice == 6) tester.option_six();

		if (choice == 7) tester.option_seven();

	} while (choice != 8);

	cout << "\nThis program has ended." << endl;


}
