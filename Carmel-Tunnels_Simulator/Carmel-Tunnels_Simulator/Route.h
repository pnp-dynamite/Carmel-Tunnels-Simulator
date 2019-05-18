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
	// Globle Routes counter
	static unsigned routes_counter; 
	Car *m_queue;
	const unsigned m_service_time;
	int m_Route_Num;
	int m_empty_slots = 0;
	int m_last_queue_inx = len-1;
public:
	bool empty_queue;
	bool full_queue;
	static unsigned len, counter;
	// Constructor
	Route();
	//	Destructor 
	~Route();
	//Copy Constructor
	//Route(const Route& R);

	//Get the index of the last car in the route
	const int Route::Route_Last_INX();

	int Route::random_num(int low, int high);

	//push_back;
	void Route::pop(int pop_inx);
	void Route::queue_advance(unsigned last_inx); 
	unsigned top();
	//size;


};

