#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

#pragma once///
using namespace std;

unsigned Route::len = 10;				// Static Initialization.	
unsigned Route::routes_counter = 1;


// Constructor
Route::Route(): m_service_time()
{
	m_queue = new Car[len];
	Route_Num = routes_counter;
	routes_counter++;
}
//	Destructor 
Route::~Route()
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