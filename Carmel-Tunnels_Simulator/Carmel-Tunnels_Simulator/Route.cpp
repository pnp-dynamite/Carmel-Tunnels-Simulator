#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

#include "Route.h"

#pragma once///
using namespace std;

unsigned Route::len = 10;				// Static Initialization.	
unsigned Route::routes_counter = 0;


// Constructor
Route::Route(): m_service_time(random_num(5, 20))
{
	
	m_queue = new Car[len];

	for (int inx = 0; inx < len; inx++)
	{
		m_queue[inx].set_Arrival_time(inx * m_service_time);
		m_queue[inx].set_exit_time((inx + 1) * m_service_time);
	}

	m_Route_Num = routes_counter;
	routes_counter++;

}

////	Destructor 
Route::~Route()
{
	delete[] m_queue;
}
////Copy Constructor
//Route::Route(const Route& RR)
//{
//
//}

Car Route::top()
{
	return m_queue[0];
}
unsigned Route::pop(unsigned pop_inx) //return the remaing free slots
{  
	//����� ����� ���� ������� ������

	m_queue[pop_inx].car_delete();
	m_empty_slots++;
	empty_check();
	return size();

}
//Function that get Car and index to push and return the next free index
unsigned Route::push_back(Car& CC,unsigned push_inx)
{
	m_queue[push_inx].Assign(CC);
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
	for (int i = 0; i < last_inx; i++)
	{
		this->m_queue[i].Assign(this->m_queue[i + 1]);
	}
}
void Route::full_check()
{
	if (m_empty_slots == len)
	{
		full_queue = true;
	}
	else
	{
		full_queue = false;
	}
}
void Route::empty_check()
{
	if (m_empty_slots == len)
	{
		empty_queue = true;
	}
	else
	{
		empty_queue = false;
	}
}

int Route::random_num(int low, int high)
{
	int num;
	/* generate secret number between low and high: */
	num = rand() % (high - low + 1) + low;
	return num;
}


