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

	//for (int inx = 0; inx < len; inx++)
	//{
	//	m_queue[inx].set_Arrival_time(inx * m_service_time);
	//	m_queue[inx].set_exit_time((inx + 1) * m_service_time);
	//}

	m_Route_Num = routes_counter;
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
unsigned Route::top()
{
	return 1;
}
void Route::pop(int pop_inx)
{  
	//����� ����� ���� ������� ������
	queue_advance(m_last_queue_inx);
	m_queue[m_last_queue_inx].car_delete();
	m_last_queue_inx--;
	m_empty_slots++;
	full_queue = (m_empty_slots < len ? false : true);

}
//const int Route::Route_Last_INX()
//{
//
//}

void Route::queue_advance(unsigned last_inx)
{
	for (int i = 0; i < last_inx; i++)
	{
		this->m_queue[i].Assign(this->m_queue[i + 1]);
	}
}


int Route::random_num(int low, int high)
{
	int num;
	/* generate secret number between low and high: */
	num = rand() % (high - low + 1) + low;
	return num;
}


