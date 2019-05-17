#include <cstdlib>
#include <iostream>
#include <ctime>

#pragma once/////


class Route
{
private:
	static unsigned route_counter;
	int*m_queue;
	const unsigned m_service_time;
	/*	Car m_queue[len];*/						// Array of Cars in the lenght of the route.




public:
	static unsigned len, counter;


	Route();





	/*push_back;
	pop;
	top;
	size;*/

};

int random_num(int low, int high);