#include <iostream>
#include <crtdbg.h>
#include <ctime>
#include <cstdlib>

#include "PayRoutes.h"

#pragma once
using namespace std;

//int PayRoutes::car_enter_counter = 0;
//int PayRoutes::car_left_counter = 0;

 //Constructor
PayRoutes::PayRoutes(int number_of_routes, int algoritem) 
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
// Create not full routes array




bool PayRoutes::check_all_empty()
{
	int all_empty = 0;
	//int i;
	for (int i = 0; i < m_num_routes; i++)
	{
		m_Routes_array[i].empty_check();
		m_Routes_array[i].empty_queue == true ? all_empty++ : all_empty--;
	}
	if(all_empty == m_num_routes)
		return true;
	else
		return false;
}
int PayRoutes::shortest_algo()
{
	int route_lowest_queue = 0;
	int Num_of_full_queues = 0;
	// working_inx is the inx with the smallest queue and not full, 
	// all full queue will set to -1 = leaving CAR
	int working_inx = 0; 
	// Check who has the smallest size of cars in the queue.
	route_lowest_queue = m_Routes_array[0].size();
	for (int i = 0; i <= m_num_routes; i++)
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
	 // working_inx is the inx with the longest queue and not full, 
	 // all full queue will set to -1 = leaving CAR
	 int working_inx = 0;
	 // Check who has the smallest size of cars in the queue.
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
	 // working_inx is the inx with the fastest queue and not full, 
	 // all full queue will set to -1 = leaving CAR
	 int working_inx = 0;
	 // Check who has the smallest size of cars in the queue.
	 //route_fastest_queue = m_Routes_array[0].get_service_time();
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
	//delete[] NotFullRoutes;
	return working_inx;
 }


Car PayRoutes::Car_Generator(int current_time, int service_time)
{
	Car CCar(current_time, current_time + service_time);
	return CCar;
}

void PayRoutes::routes_pop_check(int given_time)
{
	int i;
	for (i = 0; i < m_num_routes; i++)
	{
		if (m_Routes_array[i].top().get_Car_ET() == given_time)
		{
			m_Routes_array[i].pop();
		}
	}

}

int Simulator(int Sim_total_time, int num_of_routes, int algo)
{
	PayRoutes PP(num_of_routes, algo);
	Car A_Car;
	int time_car_generate = 2;// random_number(1, 20);
	int inx;
	for (int Current_Time = 0; Current_Time < Sim_total_time; Current_Time++)
	{
		PP.routes_pop_check(Current_Time);

		if (Current_Time%time_car_generate == 0)
		{
			if (PP.check_all_empty() == true)
				algo == 3 ? (inx = PP.algoritem_selector(PP.m_algorithm)) : (inx = random_number(0, num_of_routes-1));
			else
			inx = PP.algoritem_selector(PP.m_algorithm);

			A_Car = PP.Car_Generator(Current_Time, PP.m_Routes_array[inx].get_service_time()); 

			if (inx == -1)
			{
				A_Car.car_delete();
				PP.car_left_counter++;
			}
			else
			{
				PP.m_Routes_array[inx].push_back(A_Car, PP.m_Routes_array[inx].size());
				PP.car_enter_counter++;
			}
		}

	}
	cout << "number of car that entered: " << PP.car_enter_counter << endl;
	cout << "number of car that left: " << PP.car_left_counter << endl;
	cout << "Car Created time: " << time_car_generate << endl;
	for (int i = 0; i < PP.m_num_routes; i++)
	{
		cout << "Service time: " << PP.m_Routes_array[i].get_service_time() << endl;
	}
	return 0;
}

int random_number(int low, int high)
{
	int num;
	/* generate secret number between low and high: */
	num = rand() % (high - low + 1) + low;
	return num;
}