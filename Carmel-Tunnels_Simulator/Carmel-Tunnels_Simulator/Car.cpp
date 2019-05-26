#include <iostream>
#include <crtdbg.h>
#include <ctime>
#include <cstdlib>

#include "Car.h"

#pragma once
using namespace std;


// Constructor For spacific car
Car::Car(string car_model, int car_id, int AT, int ET)
{
	Arrival_time = AT;
	Exit_time = ET;
	Model = car_model;
	ID = car_id;
}
//// Constructor For random car
Car::Car(int AT, int ET)
{
	Arrival_time = AT;
	Exit_time = ET;
	Model = this->Model_Generator();
	ID = this->ID_Generator();
}

////	Destructor 
Car::~Car()
{
	
}

////Copy Constructor
Car::Car(const Car& C)
{
	Model = C.Model;
	ID = C.ID;
	Arrival_time = C.Arrival_time;
	Exit_time = C.Exit_time;

}

void Car::car_delete()
{
	ID = 0;
	Model = "\0";
	Exit_time = 0;
	Arrival_time = 0;
}
// Generate random model name
string Car::Model_Generator()
{
	string Model_List[10] = { "Honda", "Mazda", "Toyota", "Suzuki", "Peugeot",
												"Kia", "Volvo", "Opel", "BMW", "FIAT" };
	return Model_List[rand() % 10];
}

// Generate random 8 Digits ID number
int Car::ID_Generator()
{
	return (double)rand() / (RAND_MAX + 1) * (99999999 - 10000000) + 10000000;
}

// Getters //
int Car::get_Car_ID() const
{
	return ID;
}

string Car::get_Car_Model() const
{
	return Model;
}

int Car::get_Car_AT() const
{
	return Arrival_time;
}

int Car::get_Car_ET() const
{
	return Exit_time;
}



