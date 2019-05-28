#include <iostream>
#include <crtdbg.h>
#include <ctime>
#include <cstdlib>

#include "PayRoutes.h"

#pragma once
using namespace std;


 //Constructor
PayRoutes::PayRoutes(int number_of_routes, int algoritem, int length) 
	: m_num_routes(number_of_routes), m_algorithm(algoritem)
{
	Route::set_len(length);
	m_Routes_array = new Route[m_num_routes];
	car_enter_counter = 0;
	car_left_counter = 0;
}

////	Destructor 
PayRoutes::~PayRoutes()
{
	delete[] m_Routes_array;
}
////Copy Constructor
PayRoutes::PayRoutes(const PayRoutes& P): m_num_routes (P.m_num_routes), m_algorithm(P.m_algorithm)
{
	m_Routes_array = new Route[m_num_routes];
}


// Check every route in the pay routes if there is a car ( in index 0) that should be poped.
void PayRoutes::routes_pop_check(int given_time)
{
	for (int i = 0; i < m_num_routes; i++)
	{
		if (m_Routes_array[i].top().get_Car_ET() == given_time)
		{
			m_Routes_array[i].pop();
		}
	}
}

// Check if all the routes in the pay routes are empty.
bool PayRoutes::check_all_empty()
{
	int all_empty = 0;
	for (int i = 0; i < m_num_routes; i++)
	{
		m_Routes_array[i].empty_check();
		m_Routes_array[i].empty_queue == true ? all_empty++ : all_empty--;
	}
	if (all_empty == m_num_routes)
		return true;
	else
		return false;
}

// Choosing the spacifc algorithm funcation that need to be called.
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
	}
}
// Algorithms
int PayRoutes::shortest_algo()
{
	int route_lowest_queue = 0;
	int Num_of_full_queues = 0;
	// working_inx is the index of the route with the smallest queue and not full.
	// if all full queue index will set to -1 = leaving CAR
	int working_inx = 0; 
	// Check who has the smallest queue.
	route_lowest_queue = m_Routes_array[0].size();
	for (int i = 0; i < m_num_routes; i++)
	{
		if (m_Routes_array[i].size() <= route_lowest_queue
			&& m_Routes_array[i].full_queue == false)
		{
			route_lowest_queue = m_Routes_array[i].size();
			working_inx = i;
			Num_of_full_queues--;
		}
		else
			Num_of_full_queues++;
	}
	if (Num_of_full_queues == m_num_routes)
		return -1;
	else
		return	working_inx;
}

 int PayRoutes::longest_algo()
{
	 int route_longest_queue = 0;
	 int Num_of_full_queues = 0;
	 // working_inx is the index of the route with the longest queue and not full.
	 // if all full queue index will set to -1 = leaving CAR
	 int working_inx = 0;
	 // Check who has the longest queue.
	 for (int i = 0; i < m_num_routes; i++)
	 {
		 if (m_Routes_array[i].size() >= route_longest_queue 
								&& m_Routes_array[i].full_queue == false)
		 {
			 route_longest_queue = m_Routes_array[i].size();
			 working_inx = i;
			 Num_of_full_queues--;
		 }
		 else
			 Num_of_full_queues++;
	 }
	 if (Num_of_full_queues == m_num_routes)
		 return -1;
	 else
		 return	working_inx;
 }

 int PayRoutes::fastest_algo()
 {
	 int route_fastest_queue = 20;
	 int Num_of_full_queues = 0;
	 // working_inx is the index of the route with the fastest queue and not full.
	 // if all full queue index will set to -1 = leaving CAR
	 int working_inx = 0;
	 // Check who has the fastest queue.
	 for (int i = 0; i < m_num_routes; i++)
	 {
		 if (m_Routes_array[i].get_service_time() <= route_fastest_queue
								&& m_Routes_array[i].full_queue == false)
		 {
			 route_fastest_queue = m_Routes_array[i].get_service_time();
			 working_inx = i;
			 Num_of_full_queues--;
		 }
		 else
			 Num_of_full_queues++;
	 }
	 if (Num_of_full_queues == m_num_routes)
		 return -1;
	 else
		 return	working_inx;
 }

 // Create array of all the no't full queues and there indexes and then select route randomly
 int PayRoutes::random_queue_algo()
 {
	 int Not_Full_queues = 0;
	 int inx = 0, working_inx;
	 for (int j = 0; j < m_num_routes; j++)
	 {
		 if(m_Routes_array[j].full_queue == false)
			 Not_Full_queues++;
	 }

	 if (Not_Full_queues == 0)
		 return working_inx = -1;

	int *NotFullRoutes = new int[Not_Full_queues];
	for (int j = 0; j < m_num_routes; j++)
	{
		if (m_Routes_array[j].full_queue == false)
		{
			NotFullRoutes[inx] = j;
			inx++;
		}
	}
	working_inx = NotFullRoutes[random_number(0, Not_Full_queues-1)];
	delete[] NotFullRoutes;
	return working_inx;
 }





// Simulate given Time senario of number of payroutes in a spacific algorithm
void PayRoutes::Simulator(int Sim_total_time) 
{
	int time_car_generate = random_number(1, 5);
	int inx;
	int Counter = 0;

	for (int Current_Time = 0; Current_Time <= Sim_total_time; Current_Time++)
	{
		routes_pop_check(Current_Time);

		if (Counter == time_car_generate)
		{
			Counter = 0;
			if (check_all_empty() == true)
				m_algorithm == 3 ? (inx = algoritem_selector(m_algorithm)) : (inx = random_number(0, m_num_routes - 1));
			else
				inx = algoritem_selector(m_algorithm);

			if (inx == -1)
				car_left_counter++;
			else
			{
				int E_time;
				if (m_Routes_array[inx].size() == 0)
					E_time = Current_Time + m_Routes_array[inx].get_service_time();
				else
				{
					E_time = ((m_Routes_array[inx].size() * m_Routes_array[inx].get_service_time()) + m_Routes_array[inx].top().get_Car_ET());
				}

				Car A_Car(Current_Time, E_time);
				m_Routes_array[inx].push_back(A_Car, m_Routes_array[inx].size());
				car_enter_counter++;
			}
		}
		Counter++;
	}
}

