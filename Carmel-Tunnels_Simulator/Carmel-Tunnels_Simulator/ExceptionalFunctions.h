#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

int random_number(int low, int high);
void Multi_Simulator(int Sim_Loops, int Routes_Len, int Sim_Time);
void Result_Printer(int num_routes, int algo, long double AVG);