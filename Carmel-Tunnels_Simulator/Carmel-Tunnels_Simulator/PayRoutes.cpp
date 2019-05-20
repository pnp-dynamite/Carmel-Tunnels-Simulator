#include <iostream>
#include <crtdbg.h>
#include <ctime>
#include <cstdlib>

#include "PayRoutes.h"

#pragma once
using namespace std;

 //Constructor
PayRoutes::PayRoutes(unsigned P_time, unsigned number_of_routes, unsigned algoritem) 
	: m_num_routes(number_of_routes), m_algorithm(algoritem)
{
	m_Routes_array = new Route[m_num_routes];
	m_Simulator_time = P_time;
	m_Car_Generator_time = this->random_number(1, 20);

}
//
////	Destructor 
PayRoutes::~PayRoutes()
{
	delete[] m_Routes_array;
}
////Copy Constructor
//PayRoutes::PayRoutes(const PayRoutes& P)
//{
//
//
//}
int PayRoutes::algoritem_selector(int selection)
{
	while (selection > 4 || selection < 1)
		cout << "Invalid algoritem selection! Please enter num between 1 ti 4" << endl;

	switch (selection)
	{
	case 1:
		return shortest_algo();
	case 2:
		return longest_algo();
	case 3:
		return fastest_algo();
	case 4:
		return random_number(0, m_Routes_array[0].len);
	default:
		break;
	}
}


int PayRoutes::shortest_algo()
{
	unsigned route_lowest_queue = 0;
	
	// working_inx is the inx with the smallest queue and not full, 
	// all full queue will set to -1 = leaving CAR
	int working_inx = 0; 
	// Check who has the smallest size of cars in the queue.
	route_lowest_queue = m_Routes_array[0].size();
	for (int i = 1; i <= m_num_routes; i++)
	{
		if (m_Routes_array[i].size() < route_lowest_queue && m_Routes_array[i].full_check = false)
		{
			route_lowest_queue = m_Routes_array[i].size();
			working_inx = i;
		}
	}
	return	working_inx;

	}
 int PayRoutes::longest_algo()
{
	 unsigned route_longest_queue = 0;

	 // working_inx is the inx with the longest queue and not full, 
	 // all full queue will set to -1 = leaving CAR
	 int working_inx = 0;
	 // Check who has the smallest size of cars in the queue.
	 route_longest_queue = m_Routes_array[0].size();
	 for (int i = 1; i <= m_num_routes; i++)
	 {
		 if (m_Routes_array[i].size() > route_longest_queue && m_Routes_array[i].full_check = false)
		 {
			 route_longest_queue = m_Routes_array[i].size();
			 working_inx = i;
		 }
	 }
	 return	working_inx;
 }
 int PayRoutes::fastest_algo()
 {
	 unsigned route_fastest_queue = 0;

	 // working_inx is the inx with the fastest queue and not full, 
	 // all full queue will set to -1 = leaving CAR
	 int working_inx = 0;
	 // Check who has the smallest size of cars in the queue.
	 route_fastest_queue = m_Routes_array[0].m_service_time;
	 for (int i = 1; i <= m_num_routes; i++)
	 {
		 if (m_Routes_array[i].size() > route_fastest_queue && m_Routes_array[i].full_check = false)
		 {
			 route_fastest_queue = m_Routes_array[i].m_service_time;
			 working_inx = i;
		 }
	 }
	 return	working_inx;
 }
 int PayRoutes::random_algo()
 {

 }




int PayRoutes::random_number(int low, int high)
{
	int num;
	/* generate secret number between low and high: */
	num = rand() % (high - low + 1) + low;
	return num;
}






