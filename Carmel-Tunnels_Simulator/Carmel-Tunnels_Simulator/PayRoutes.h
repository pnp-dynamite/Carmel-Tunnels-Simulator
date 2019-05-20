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



public:
	// Constructor
	PayRoutes(unsigned number_of_routes, unsigned algoritem = 1);
	//	Destructor 
	~PayRoutes();
	//Copy Constructor
	//PayRoutes(const PayRoutes& P);

	int PayRoutes::algoritem_selector(int selection);
	int PayRoutes::random_number(int low, int high);
	
	

	//int PayRoutes::routes_checker(int num_of_routes, int algoritem);
	// כדי להפוך לפונקציה אחת כוללת
	int PayRoutes::shortest_algo();
	int PayRoutes::longest_algo();
	int PayRoutes::fastest_algo();
	int PayRoutes::random_queue_algo();


};