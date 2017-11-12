#include <iostream>
#include <string>
#include "Car.h"
using namespace std;

#define NUM_OF_CARS 2
#define SIZE_OF_COLOR 10

/*
Checks if car details are valid
@param year
@param engineVolume
@color
@return true/false
*/
bool input_check(unsigned int year, double engineVolume, char color[SIZE_OF_COLOR])
{
	if (year <= 0 || engineVolume <= 0 || strlen(color) < 0 || strlen(color) > SIZE_OF_COLOR - 1)
	{
		return false;
	}

	return true;
}

int main()
{
	Car* cars[NUM_OF_CARS];
	string make, model;
	int year;
	double engineVolume;
	char color[SIZE_OF_COLOR];
	bool check_result;
	for (int i = 0; i < NUM_OF_CARS; i++)
	{
		cout << "Please enter car "<<i+1<<" details:\nmake, model, year, engine volume (in cc) and color (9 chars) " << endl;
		cin >> make >> model >> year >> engineVolume >> color;
		check_result = input_check(year, engineVolume, color);
		if (!check_result || cin.fail())
		{
			cout << "ERROR: invalid input, please try again" << endl;
			cin.clear();
			string ignoreline;
			getline(cin, ignoreline);
			i = i-1;
			continue;
		}
		cars[i] = new Car(make, model, year, engineVolume, color);
	}
	cout << "Car 1 Details:" << endl;
	cars[0]->print_car();
	cout << endl << "Car 2 Details:" << endl;
	cars[1]->print_car();
	cout << endl << endl;
	
	cout << "Comparisons:" << endl;
	if (cars[0]->compare_by_year(cars[1]) == cars[0])
	{
		cout << "Car 1 is older" << endl;
	}

	else
	{
		cout << "Car 2 is older" << endl;
	}

	if (cars[0]->compare_by_engine_volume(cars[1]) == cars[0])
	{
		cout << "Car 1 has a greater engine volume" << endl;
	}

	else
	{
		cout << "Car 2 has a greater engine volume" << endl;
	}

	for (int i = 0; i < NUM_OF_CARS; i++)
	{
		delete cars[i];
	}
}