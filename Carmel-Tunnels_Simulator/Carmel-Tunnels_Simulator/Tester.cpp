#include "Car.h"
#include "Route.h"
#include "PayRoutes.h"
#include "ExceptionalFunctions.h"

#pragma once
using namespace std;


int main()
{
	srand(time(0));

	// Gets the Simulator loops number, the lenght of all the routes, Simulator "Parking time"
	Multi_Simulator(100, 5, 86400);

	cout << endl << "Leaks: " << _CrtDumpMemoryLeaks() << endl;
	return 0;
}