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
	const unsigned m_num_routes;
	// between 1 to 4: 1.shortest 2.longestv 3.fastest 4.random
	const unsigned m_algorithm;
	Route *m_Routes_array;
	unsigned m_Simulator_time;
	unsigned m_Car_Generator_time;


public:
	// Constructor
	PayRoutes(unsigned P_time = 60, unsigned route_num = 1, unsigned algoritem = 1);
	//	Destructor 
	~PayRoutes();
	//Copy Constructor
	//PayRoutes(const PayRoutes& P);
	void PayRoutes::algoritem_bank(unsigned selection);
	int PayRoutes::random_number(int low, int high);
	Car PayRoutes::m_Car_Generator_time();
};