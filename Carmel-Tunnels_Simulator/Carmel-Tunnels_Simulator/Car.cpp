#include <iostream>
#include <crtdbg.h>
#include <ctime>
#include <cstdlib>

#include "Car.h"

#pragma once
using namespace std;

// Constructor
Car::Car()
{
	
	Model = this->Model_Generator();
	ID = this->ID_Generator();
}

//	Destructor 
Car::~Car()
{


}
//Copy Constructor
Car::Car(const Car&)
{


}

// Generate random model name
basic_string<char> Car::Model_Generator()
{
	srand(time(NULL));
	basic_string<char> Model_List[10] = { "Honda", "Mazda", "Toyota", "Suzuki", "Peugeot", "Kia", "Volvo", "Opel", "BMW", "FIAT" };
	return Model_List[rand() % 10];
}

// Generate random 8Digits ID number
unsigned Car::ID_Generator()
{
	srand(time(NULL));
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
