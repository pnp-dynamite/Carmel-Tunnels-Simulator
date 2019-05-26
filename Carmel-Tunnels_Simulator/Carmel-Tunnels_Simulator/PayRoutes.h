#include <iostream>
#include <ctime>
#include <string>

#include "Route.h"

#pragma once
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG

class PayRoutes {

private:
	const int m_num_routes;
	const int m_algorithm;
	Route *m_Routes_array;

public:
	long double car_enter_counter;
	long double car_left_counter;

	// Constructor
	PayRoutes::PayRoutes(int number_of_routes, int algoritem, int length);
	//	Destructor 
	~PayRoutes();
	//Copy Constructor
	PayRoutes(const PayRoutes& P);

	int PayRoutes::algoritem_selector(int selection);
	int PayRoutes::shortest_algo();
	int PayRoutes::longest_algo();
	int PayRoutes::fastest_algo();
	int PayRoutes::random_queue_algo();

	bool PayRoutes::check_all_empty();
	void PayRoutes::routes_pop_check(int given_time);

	 void PayRoutes::Simulator(int Sim_total_time);

};

