#pragma once

#include <string>
#include <iostream>
#include "Car.h"

using namespace std;//test

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
	const unsigned algorithm;
	Routes EnterRoutesArray[m_num_routes];


public:
	// Constructor
	PayRoutes();
	//	Destructor 
	~PayRoutes();
	//Copy Constructor
	PayRoutes(const PayRoutes&);

};