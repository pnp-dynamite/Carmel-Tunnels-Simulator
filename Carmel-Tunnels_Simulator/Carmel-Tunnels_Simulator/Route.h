#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

#include "Car.h"

using namespace std;
#pragma once

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
	int m_empty_slots = len;


public:
	bool empty_queue = true;
	bool full_queue = false;

	// Globle Routes counter
	static int routes_counter;
	static int len;

	// Constructor
	Route();
	//	Destructor 
	~Route();
	//Copy Constructor
	Route(const Route& RR);

	void Route::push_back(Car& CC, int push_inx);
	void Route::pop();
	void Route::queue_advance(); 

	void Route::full_check();
	void Route::empty_check();

	int Route::get_service_time();
	Car Route::top();
	int Route::size();
	static void Route::set_len(int lenght);
};
