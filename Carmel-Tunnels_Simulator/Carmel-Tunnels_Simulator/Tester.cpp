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

	cout << "4 , 1" << endl;
	for (int i = 0; i < 10; i++)
	{
		Simulator(86400, 1, 2);
	}
	
	//cout << "5 , 2" << endl;
	//Simulator(86400, 3, 2);
	//cout << "5 , 3" << endl;
	//Simulator(86400, 2, 3);
	//cout << "5 , 4" << endl;
	//Simulator(86400, 5, 3);

	return 0;
}