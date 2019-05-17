#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

#include "Route.h"

#pragma once///
using namespace std;

unsigned Route::len = 10;				// Static Initialization.	
unsigned Route::routes_counter = 1;


// Constructor
Route::Route(): m_service_time(random_num(5, 20))
{
	
	m_queue = new Car[len];

	for (int inx = 0; inx < len; inx++)
	{
		m_queue[inx].set_Arrival_time(inx * m_service_time);
		m_queue[inx].set_exit_time((inx+1) * m_service_time);
	}

	Route_Num = routes_counter;
	routes_counter++;
}
////	Destructor 
Route::~Route()
{
	delete[] m_queue;
}
////Copy Constructor
//Route::Route(const Route& R)
//{
//
//}
//
//const int Route::Route_Last_INX()
//{
//
//}

int Route::random_num(int low, int high)
{
	int num;
	/* generate secret number between low and high: */
	num = rand() % (high - low + 1) + low;
	return num;
}


