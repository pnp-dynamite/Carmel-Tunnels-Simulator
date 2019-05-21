#include <iostream>
#include <crtdbg.h>
#include <ctime>
#include <cstdlib>

#include "PayRoutes.h"

#pragma once
using namespace std;

 //Constructor
PayRoutes::PayRoutes(unsigned number_of_routes, unsigned algoritem) 
	: m_num_routes(number_of_routes), m_algorithm(algoritem)
{
	m_Routes_array = new Route[m_num_routes];

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
		return random_queue_algo();
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
		if (m_Routes_array[i].size() < route_lowest_queue 
									&& m_Routes_array[i].full_queue == false)
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
		 if (m_Routes_array[i].size() > route_longest_queue 
								&& m_Routes_array[i].full_queue == false)
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
		 if (m_Routes_array[i].size() > route_fastest_queue && m_Routes_array[i].full_queue == false)
		 {
			 route_fastest_queue = m_Routes_array[i].m_service_time;
			 working_inx = i;
		 }
	 }
	 return	working_inx;
 }

 int PayRoutes::random_queue_algo()
 {
	 for (int i = 1; i <= m_num_routes; i++)
	 {
		if( m_Routes_array[i].full_queue == false)
			 return i;
	}
	 return -1;
 }


int PayRoutes::random_number(int low, int high)
{
	int num;
	/* generate secret number between low and high: */
	num = rand() % (high - low + 1) + low;
	return num;
}

Car PayRoutes::Car_Generator(unsigned current_time, unsigned service_time)
{
	Car CCar(current_time, current_time + service_time);
	return CCar;
}

int PayRoutes::Simulator(int Sim_total_time, int num_of_routes, int algo)
{
	PayRoutes PP(num_of_routes, algo);
	int time_car_generate = PP.random_number(1, 20);
	int inx;
	for (int Current_Time = 0; Current_Time < Sim_total_time; Current_Time++)
	{
		if (Current_Time == time_car_generate)
		{
			inx = PP.algoritem_selector(PP.m_algorithm);
			Car A_Car = PP.Car_Generator(Current_Time, PP.m_Routes_array[inx].m_service_time);
		}
		


	}
}

