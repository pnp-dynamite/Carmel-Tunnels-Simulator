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
	int m_empty_slots = len;

public:
	Car *m_queue;
	const unsigned m_service_time;
	// Globle Routes counter
	static unsigned routes_counter;
	static unsigned len;

	bool empty_queue = true;
	bool full_queue = false;


	//static unsigned len, counter;
	// Constructor
	Route();
	//	Destructor 
	~Route();
	//Copy Constructor
	Route(const Route& RR);

	void Route::full_check();
	void Route::empty_check();

	int Route::random_num(int low, int high);
	// the function get the Car enter indnx and return the remming free slots in the queue.
	unsigned Route::push_back(Car& CC, unsigned push_inx);
	bool Route::car_time_out();
	// the function get the Car remoce indnx and return the remming free slots in the queue.
	void Route::pop(unsigned pop_inx);

	void Route::queue_advance(unsigned last_inx); 

	Car Route::top();
	const unsigned Route::size();


};

