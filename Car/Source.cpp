#include <iostream>
#include <string>
#include "Car.h"
using namespace std;

#define SIZE_OF_COLOR 10

/*
Checks if car details are valid
@param year
@param engineVolume
@color
@return true/false
*/
bool input_check(unsigned int year, double engineVolume, const char color[SIZE_OF_COLOR])
{
	if (year <= 0 || engineVolume <= 0 || strlen(color) < 0 || strlen(color) > SIZE_OF_COLOR - 1)
	{
		return false;
	}

	return true;
}

/*
Gets input of a car and initialize a new car object
@param index - index of the car (0/1)
@param car - the car to initialize
*/
void getInput(int index, Car& const car)
{
	string make, model;
	int year;
	double engineVolume;
	char color[SIZE_OF_COLOR];
	bool check_result, finished = false;

	while (!finished)
	{
		cout << "Please enter car " << index << " details:\nmake, model, year, engine volume (in cc) and color (9 chars) " << endl;
		cin >> make >> model >> year >> engineVolume >> color;
		check_result = input_check(year, engineVolume, color);
		if (!check_result || cin.fail())
		{
			cout << "ERROR: invalid input, please try again" << endl;
			cin.clear();
			string ignoreline;
			getline(cin, ignoreline);
			continue;
		}

		finished = true;
	}

	car.setMake(make);
	car.setModel(model);
	car.setYear(year);
	car.setEngineVolume(engineVolume);
	car.setColor(color);
}

int main()
{
	Car car1, car2;
	getInput(1, car1);
	getInput(2, car2);

	cout << "Car 1 Details:" << endl;
	car1.print_car();
	cout << endl << "Car 2 Details:" << endl;
	car2.print_car();
	cout << endl << endl;
	
	cout << "Comparisons:" << endl;
	if (car1.compare_by_year(car2) > 0)
	{
		cout << "Car 1 is older" << endl;
	}

	else
	{
		cout << "Car 2 is older" << endl;
	}

	if (car1.compare_by_engine_volume(car2) < 0)
	{
		cout << "Car 1 has a greater engine volume" << endl;
	}

	else
	{
		cout << "Car 2 has a greater engine volume" << endl;
	}
}