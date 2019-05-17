#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Route.h"

#pragma once///


using namespace std;

unsigned Route::len = 10;				// Static Initialization.	
unsigned Route::route_counter = 1;
static unsigned len;

// Constructor
Route::Route()
{

}
//	Destructor 
~Route::Route()
{

}
//Copy Constructor
Route::Route(const Route&)
{

}

const int Route::Route_Last_INX()
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