#include <iostream>
#include <crtdbg.h>
#include <ctime>
#include <cstdlib>

#include "PayRoutes.h"

#pragma once
using namespace std;

 //Constructor
PayRoutes::PayRoutes(unsigned P_time, unsigned route_num, unsigned algoritem) 
	: m_num_routes(route_num), m_algorithm(algoritem)
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

Car PayRoutes::Car_Generator(unsigned create_time, unsigned service_time)
{
	Car CCar(create_time, create_time + service_time);
	return CCar;
}

unsigned PayRoutes::shortest_algo(Car Ccar)
{
	for (int i = 0; i <= m_num_routes; i++)
	{

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

