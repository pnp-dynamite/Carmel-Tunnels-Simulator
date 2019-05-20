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

class Simulator {

private:
	const unsigned m_num_routes;
	unsigned m_Simulator_time;
	unsigned m_Car_Generator_time;



public:
	// Constructor
	Simulator(unsigned P_time = 60, unsigned number_of_routes = 1, unsigned algoritem = 1);
	//	Destructor 
	~Simulator();
	//Copy Constructor
	//Simulator(const Simulator& P);
