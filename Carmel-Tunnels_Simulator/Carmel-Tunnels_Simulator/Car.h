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

	string Model;
	unsigned ID;
	unsigned Arrival_time = 0;
	unsigned Exit_time = 0;


public:
	// Constructor For spacific car
	Car(string car_model = "",unsigned car_id = 0, unsigned AT = 0, unsigned ET = 0);
	// Constructor For random car
	Car::Car(unsigned AT, unsigned ET);

	//	Destructor 
	~Car();
	//Copy Constructor
	Car(const Car& A);

	// Generate random model name
	string Car::Model_Generator();
	// Generate random 8digits ID number
	unsigned Car::ID_Generator();

	// Getters
	const int Car::get_Car_ID();
	const string Car::get_Car_Model();

	const int Car::get_Car_AT(); //AT - Arrival Time
	const int Car::get_Car_ET(); //ET - Exit Time

	//setters
	void Car::set_Arrival_time(int AT);
	void Car::set_exit_time(int ET);
	void Car::car_delete();
	Car Car::Assign(Car& CC);
	bool Car::car_validation(Car& CCar);
};
