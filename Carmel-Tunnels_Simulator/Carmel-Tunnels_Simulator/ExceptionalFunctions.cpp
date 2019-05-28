#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

#include "ExceptionalFunctions.h"
#include "PayRoutes.h"

#pragma once///
using namespace std;


// Generate random number between the LOW number and the HIGH number (including)
int random_number(int low, int high)
{
	int num;
	num = rand() % (high - low + 1) + low;
	return num;
}

// Runs a simulation of a range of Pay routes for a given time for each simulation and the number of each simulator
void Multi_Simulator(int Sim_Loops, int Routes_Len, int Sim_Time)
{
	long double AVG = 0, enter = 0, left = 0, Best_AVG = 35;
	int Best_Routes = 2, Best_Algo = 0;
	bool run_once = true;
	
	for (int num_routes = 2; num_routes <= 5; num_routes++)
	{
		for (int algo = 1; algo <= 4; algo++)
		{
			enter = 0, left = 0;
			for (int i = 0; i < Sim_Loops; i++)
			{
				PayRoutes PP(num_routes, algo, Routes_Len);
				PP.Simulator(Sim_Time);
				enter += PP.car_enter_counter;
				left += PP.car_left_counter;
			}
			AVG = (left / (left + enter)) * 100;

			// Calling Best AVG Function ... (all below)
			if (AVG <= Best_AVG && run_once)
			{
				run_once = false;
				Best_AVG = AVG;
				Best_Routes = num_routes;
			}
			if (AVG <= Best_AVG && num_routes == Best_Routes)
			{
				Best_Algo = algo;
				Best_AVG = AVG;
				Best_Routes = num_routes;
			}
			Result_Printer(num_routes, algo, AVG);
		}
	}

	cout << " | Best Simulation: " << endl;
	Result_Printer(Best_Routes, Best_Algo, Best_AVG);
}
	
// Print the result to the screen
void Result_Printer(int num_routes, int algo, long double AVG)
{
const int width = 20;
static bool runOnce = true;
const string sep = " |";
const int total_width = width * 3;
const string line = sep + string(total_width + 5, '-') + '|';
string algos;
switch (algo)
{
case 1:
	algos.assign("Shortest");
	break;
case 2:
	algos.assign("Longest");
	break;
case 3:
	algos.assign("Fastest");
	break;
case 4:
	algos.assign("Random");
	break;
}

if (runOnce)					// Printing top table once;
{
	cout << line << endl << sep
		<< setw(width) << "# Of Routes" << sep
		<< setw(width) << "Algorithm" << sep
		<< setw(width) << "Rate Left in %" << sep << endl << line << endl;
	runOnce = false;
}

cout << sep << setw(width) << num_routes << sep
<< setw(width) << algos << sep
<< setw(width) << AVG << sep << endl;
}
