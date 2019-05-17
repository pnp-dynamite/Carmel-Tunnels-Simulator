#include <iostream>
#include <crtdbg.h>
#include <ctime>
#include <cstdlib>

#include "PayRoutes.h"

#pragma once
using namespace std;

 //Constructor
PayRoutes::PayRoutes() : m_num_routes(5), algorithm()
{
	Routes_array = new Route[m_num_routes];
}
//
////	Destructor 
PayRoutes::~PayRoutes()
{
	delete[] Routes_array;
}
////Copy Constructor
//PayRoutes::PayRoutes(const PayRoutes& P)
//{
//
//
//}

