//front.h
//Drake Wheeler
//Karla Fant
//CS163
//Program 4
//5/29/2023
//This is the header file for the front class
#include "tree.h"


class front
{
		public:
			front(void);
			~front(void);
			void welcome(void);
			int menu(void);
			void option_one(void);
			void option_two(void);
			void option_three(void);
			void option_four(void);
			void option_five(void);
			void option_six(void);
			void option_seven(void);

		private:
			void get_char_array(char member_name[], char actual_temp_member[]);
			void get_front_trip(front_trip& trip_info);
			int get_integer(void);

			tree trips;
};
