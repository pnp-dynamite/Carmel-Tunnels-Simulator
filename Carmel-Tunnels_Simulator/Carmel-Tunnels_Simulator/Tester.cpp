#include "Car.h"
#include "Route.h"
#include "PayRoutes.h"
#pragma once
using namespace std;

int main()
{
	srand(time(0));
	//Route RR;
	//RR.pop(0);
	//Car CC(2, 4);
	//RR.push_back(CC, 0);

	
	Simulator(30, 2, 4);

	return 0;
}