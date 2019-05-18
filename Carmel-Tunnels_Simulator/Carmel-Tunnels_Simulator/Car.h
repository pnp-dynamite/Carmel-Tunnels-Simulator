#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>


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
	


public:
	unsigned Arrival_time = 0; 
	unsigned Exit_time = 0; 

	// Defualt Constructor
	Car::Car();
	// Constructor For spacific car
	Car(basic_string<char> car_model = "",unsigned car_id = 0, unsigned AT = 0);
	// Constructor For random car
	Car::Car(unsigned AT);
	//	Destructor 
	//~Car();
	//Copy Constructor
	Car(const Car& A);

	// Generate random model name
	basic_string<char> Model_Generator();
	// Generate random 8digits ID number
	unsigned ID_Generator();

	const int Car::get_Car_ID();
	const basic_string<char> Car::get_Car_Model();
	const int Car::get_Car_AT(); //AT - Arrival Time

	void Car::set_Arrival_time(int AT);
	void Car::set_exit_time(int ET);
	void Car::car_delete();
	Car Car::Assign(Car& CC);

	int Car::random_num(int low, int high);
};
