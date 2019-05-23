#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

#include "Car.h"

using namespace std;
#pragma once/////

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG

class Route {
private:
	int m_Route_Num;
	const int m_service_time;
	Car *m_queue;

public:
	int m_empty_slots = len;
	// TBD - maybe should be private
	// Globle Routes counter
	static int routes_counter;
	static int len;

	bool empty_queue = true;
	bool full_queue = false;


	//static int len, counter;
	// Constructor
	Route();
	//	Destructor 
	~Route();
	//Copy Constructor
	Route(const Route& RR);

	void Route::full_check();
	void Route::empty_check();

	int Route::get_service_time();

	// the function get the Car enter indnx and return the remming free slots in the queue.
	void Route::push_back(Car& CC, int push_inx);
	bool Route::car_time_out();
	// the function get the Car remoce indnx and return the remming free slots in the queue.
	void Route::pop();

	void Route::queue_advance(); 

	Car Route::top();
	int Route::size();

	friend int random_number(int low, int high);

};

