#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

#include "Route.h"

#pragma once///
using namespace std;

int Route::len = 1;				// Static Initialization.	
int Route::routes_counter = 1;


// Constructor
Route::Route() : m_service_time(random_number(Min_Route_Service_Time, Max_Route_Service_Time)), m_empty_slots(len), m_Route_Num(routes_counter++)
{
	m_queue = new Car[len];
}

////	Destructor 
Route::~Route()
{
	delete[] m_queue;
}
////Copy Constructor
Route::Route(const Route& RR): m_service_time(RR.m_service_time)
{
	m_queue = new Car[len];
	for (int i = 0; i < len; i++)
		m_queue[i] = m_queue[i];

	m_empty_slots = RR.m_empty_slots;
	m_Route_Num = RR.m_Route_Num;
}
int Route::get_service_time()
{
	return m_service_time;
}
Car Route::top()
{
	return m_queue[0];
}
void Route::pop() 
{  
	top().car_delete();
	m_empty_slots++;
	empty_check();
	full_check();
	queue_advance();
}

//Function that get Car and index to push
void Route::push_back(Car& CC,int push_inx)
{
	m_queue[push_inx] = CC;
	m_empty_slots--;
	full_check();
	empty_check();
} 

int Route::size()
{
	return (len - m_empty_slots);
}
void Route::queue_advance()
{
	int j = 1;
	for (int i = 0; i < len && j < len; i++, j++)
		this->m_queue[i] = this->m_queue[j];

	this->m_queue[len - 1].car_delete();
}
void Route::full_check() // Maybe to change to full_flag_updater
{
	full_queue = (m_empty_slots == 0 ? true : false);
}
void Route::empty_check()  // Maybe to change to empty_flag_updater
{
	empty_queue = (m_empty_slots == len ? true : false);
}

 void Route::set_len(int lenght)
 {
	 len = lenght;
}
