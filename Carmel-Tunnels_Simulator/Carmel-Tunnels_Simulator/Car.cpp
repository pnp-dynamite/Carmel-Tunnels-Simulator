#include <iostream>
#include <crtdbg.h>
#include <ctime>
#include <cstdlib>

#include "Car.h"

#pragma once
using namespace std;


// Constructor For spacific car
Car::Car(basic_string<char> car_model, unsigned car_id, unsigned AT, unsigned ET)
{
	Arrival_time = AT;
	Exit_time = ET;
	Model = car_model;
	ID = car_id;
}
//// Constructor For random car
Car::Car(unsigned AT, unsigned ET)
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

}
void Car::car_delete()
{
	ID = 0;
	Model = "\0";
	Exit_time = 0;
	Arrival_time = 0;
}
// Generate random model name
basic_string<char> Car::Model_Generator()
{
	basic_string<char> Model_List[10] = { "Honda", "Mazda", "Toyota", "Suzuki", "Peugeot",
														"Kia", "Volvo", "Opel", "BMW", "FIAT" };
	return Model_List[rand() % 10];
}

// Generate random 8Digits ID number
unsigned Car::ID_Generator()
{
	return (double)rand() / (RAND_MAX + 1) * (99999999 - 10000000) + 10000000;
}

const int Car::get_Car_ID()
{
	return ID;
}
const basic_string<char> Car::get_Car_Model()
{
	return Model;
}
const int Car::get_Car_AT()
{
	return Arrival_time;
}


void Car::set_Arrival_time(int AT)
{
	Arrival_time = AT;
}
void Car::set_exit_time(int ET)
{
	Exit_time = ET;
}
Car Car::Assign(Car& CC) //TBD change to operator overload =
{
	Model = CC.Model;
	ID = CC.ID;
	Arrival_time = CC.Arrival_time;
	Exit_time = CC.Exit_time;
	return *this;
}

int Car::random_num(int low, int high)
{
	int num;
	/* generate secret number between low and high: */
	num = rand() % (high - low + 1) + low;
	return num;
}
