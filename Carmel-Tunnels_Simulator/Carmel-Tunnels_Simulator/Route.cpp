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
Route::Route(): m_service_time()
{
	m_queue = new Car[len];
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

int random_num(int low, int high)
{
	/* initialize random seed: */
	srand(time(NULL));
	int num;
	/* generate secret number between low and high: */
	num = rand() % (high - low + 1) + low;
	return num;
}


