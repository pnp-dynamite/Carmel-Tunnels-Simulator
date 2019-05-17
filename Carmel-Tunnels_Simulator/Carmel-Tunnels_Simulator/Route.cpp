#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Route.h"
#pragma once///


using namespace std;

unsigned Route::len = 10;				// Static Initialization.	
unsigned Route::route_counter = 1;


Route::Route() :m_service_time()
{

}



int random_num(int low, int high)
{
	/* initialize random seed: */
	srand(time(NULL));
	int num;
	/* generate secret number between low and high: */
	num = rand() % (high - low + 1) + low;
	return num;
}


int main()
{
	int x = 0;
	cout << x << endl;
	x = random_num(10000000, 99999999);
	cout << x << endl;
}