#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

#include "Route.h"

#pragma once///
using namespace std;

unsigned Route::len = 5;				// Static Initialization.	
unsigned Route::routes_counter = 0;


// Constructor
Route::Route() : m_service_time(random_num(5, 20))
{
	
	m_queue = new Car[len];
	m_Route_Num = routes_counter;
	routes_counter++;

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
	{
		m_queue[i].Assign(RR.m_queue[i]);
	}
	m_empty_slots = RR.m_empty_slots;
	m_Route_Num = RR.m_Route_Num;
}

Car Route::top()
{
	return m_queue[0];
}
unsigned Route::pop(unsigned pop_inx) //return the remaing free slots
{  
	//תיעוד בקובץ פרטי המכונית היוצאת

	m_queue[pop_inx].car_delete();
	m_empty_slots++;
	empty_check();
	return size();

}
//Function that get Car and index to push and return the next free index
unsigned Route::push_back(Car& CC,unsigned push_inx)
{
	m_queue[push_inx].Assign(CC);
	if(full_queue != true)
		queue_advance(push_inx);

	//m_last_queue_inx--;
	m_empty_slots--;
	empty_check();
	return size();
} 

const unsigned Route::size()
{
	return len - m_empty_slots;
}
void Route::queue_advance(unsigned last_inx)
{
	for (int i = 0; i < size(); i++)
	{
		this->m_queue[i].Assign(this->m_queue[i + 1]);
	}
}
void Route::full_check()
{
	full_queue = (m_empty_slots == 0 ? true : false);
}
void Route::empty_check()
{
	empty_queue = (m_empty_slots == len ? true : false);
}

int Route::random_num(int low, int high)
{
	int num;
	/* generate secret number between low and high: */
	num = rand() % (high - low + 1) + low;
	return num;
}


