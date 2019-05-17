#pragma once

#include <string>
#include <iostream>
#include "PayRoutes.h"
#include "Route.h"

using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG

class Car {
private:
	basic_string<char> Model;
	unsigned ID;
	unsigned Arrival_time; //TBD- maybe should be public.

public:
	// Constructor
	Car();
	//	Destructor 
	~Car();
	//Copy Constructor
	Car(const Car&);

	// Generate random model name
	basic_string<char> Model_Generator();
	// Generate random 8digits ID number
	unsigned ID_Generator();

	const int Car::get_Car_ID();
	const basic_string<char> Car::get_Car_Model();
	const int Car::get_Car_AT() //AT - Arrival Time
};
