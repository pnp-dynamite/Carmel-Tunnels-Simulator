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
	int ID;
	int Arrival_time;
	int Exit_time;


public:
	// Constructor For spacific car
	Car(string car_model = "",int car_id = 0, int AT = -1, int ET = -1); // fix
	// Constructor For random car
	Car::Car(int AT, int ET);

	//	Destructor 
	~Car();
	//Copy Constructor
	Car(const Car& A);

	// Generate random model name
	string Car::Model_Generator();
	// Generate random 8digits ID number
	int Car::ID_Generator();

	// Getters
	const int Car::get_Car_ID();
	const string Car::get_Car_Model();
	const int Car::get_Car_AT(); //AT - Arrival Time
	const int Car::get_Car_ET(); //ET - Exit Time

	//setters
	void Car::car_delete();
	Car Car::Assign(Car& CC);

};
