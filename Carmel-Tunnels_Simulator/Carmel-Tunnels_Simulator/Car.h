#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

#include "PayRoutes.h"
#include "Route.h"

#pragma once
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
	unsigned Arrival_time = 0; //TBD- maybe should be public.
	unsigned Exit_time = 0; //TBD- maybe should be public.


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
	const int Car::get_Car_AT(); //AT - Arrival Time

	void Car::set_Arrival_time(int AT);
	void Car::set_exit_time(int ET);
};
