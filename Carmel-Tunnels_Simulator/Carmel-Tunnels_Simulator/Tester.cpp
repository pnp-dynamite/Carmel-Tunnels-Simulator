#include "Car.h"
#include "Route.h"
#include "PayRoutes.h"
#pragma once
using namespace std;

int main()
{
	srand(time(0));

	for (int i = 0; i < 2; i++)
	{
		Simulator(86400, 2, 2);
	}

	cout << "Leaks: " << _CrtDumpMemoryLeaks() << endl;

	return 0;
}