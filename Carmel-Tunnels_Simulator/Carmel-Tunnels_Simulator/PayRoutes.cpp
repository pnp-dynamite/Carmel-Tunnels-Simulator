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
void PayRoutes::algoritem_bank(unsigned selection)
{
	while (selection > 4 || selection < 1)
		cout << "Invalid algoritem selection! Please enter num between 1 ti 4" << endl;

	switch (selection)
	{
	case 1:

	case 2:

	case 3:

	case 4:

	default:
		break;
	}
}


unsigned PayRoutes::shortest_algo(Car Ccar)
{
	unsigned route_lowest_queue = 0;
	unsigned working_inx = 0;
	// Check who has the smallest size of cars in the queue.
	route_lowest_queue = m_Routes_array[0].size();
	for (int i = 1; i <= m_num_routes; i++)
	{
		if (m_Routes_array[i].size() > route_lowest_queue)
		{
			route_lowest_queue = m_Routes_array[i].size();
			working_inx = i;
		}

	}
		
	
	
}
//unsigned PayRoutes::longest_algo(Car Ccar);
//unsigned PayRoutes::fastest_algo(Car Ccar);
//unsigned PayRoutes::random_algo(Car Ccar);













int PayRoutes::random_number(int low, int high)
{
	int num;
	/* generate secret number between low and high: */
	num = rand() % (high - low + 1) + low;
	return num;
}

