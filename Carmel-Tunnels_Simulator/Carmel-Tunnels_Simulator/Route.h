#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Car.h"
#include "PayRoutes.h"


#pragma once/////


class Route
{
private:

	static unsigned route_counter;
	int*m_queue;
	const unsigned m_service_time;
	Car m_queue[];					// Array of Cars in the lenght of the route.

public:
	static unsigned len, counter;
	// Constructor
	Route();
	//	Destructor 
	~Route();
	//Copy Constructor
	Route(const Route&);

	//Get the index of the last car in the route
	const int Route::Route_Last_INX();

	int Route::random_num(int low, int high);

	/*push_back;
	pop;
	top;
	size;*/

};

