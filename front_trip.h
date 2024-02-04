//front_trip.h
//This file holds the struct front_trip which is used to temporarily hold details about a trip

const int MAX {100};

struct front_trip
{
	char name[MAX];
	char location[MAX];
	char attraction[MAX];
	char when[MAX];
	char travel[MAX];
	char climate[MAX];
};
