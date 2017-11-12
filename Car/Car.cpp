#include <iostream>
#include <string>
#include <assert.h>
#include "Car.h"

using namespace std;

#define SIZE_OF_COLOR 10

// constructors
Car::Car() {}

Car::Car(string c_make, string c_model, unsigned int c_year, double c_engineVolume, char c_color[SIZE_OF_COLOR])
{
	assert(c_year >= 0 && c_engineVolume >= 0 && strlen(c_color) <= SIZE_OF_COLOR - 1 && strlen(c_color) >= 0);
	make = c_make;
	model = c_model;
	year = c_year;
	engineVolume = c_engineVolume;
	strncpy_s(color, c_color, SIZE_OF_COLOR);
}

// setters 

void Car::setMake(string value)
{
	make = value;
}

void Car::setModel(string value)
{
	model = value;
}

void Car::setYear(unsigned int value)
{
	year = value;
}

void Car::setEngineVolume(double value)
{
	engineVolume = value;
}

void Car::setColor(char value[SIZE_OF_COLOR])
{
	strncpy_s(color, value, SIZE_OF_COLOR);
}

// getters

string Car::getMake() const
{
	return make;
}

string Car::getModel() const
{
	return model;
}

unsigned int Car::getYear() const
{
	return year;
}

double Car::getEngineVolume() const
{
	return engineVolume;
}

char* Car::getColor()
{
	return color;
}

/*
Prints the car details
*/
void Car::print_car() const
{
	cout << "Make: " + make << endl;
	cout << "Model: " + model << endl;
	cout << "Year: " + to_string(year) << endl;
	cout << "Engine Volume: " + to_string(engineVolume) << endl;
	cout << "Color: " + string(color) << endl;
}

/*
Compare two cars by year
@param car - the second car to compare
@return the older car
*/
int Car::compare_by_year(Car &car) const
{
	int result = 0; // default value: cars are equal
	if (this->year < car.year) // left car is older
	{
		result = 1;
	}
	else if (this->year > car.year) // right car is older
	{
		result = -1;
	}
	
	return result;
}

/*
Compare two cars by engine volume
@param car - the second car to compare
@return the car that has a greater engine volume
*/
int Car::compare_by_engine_volume(Car &car) const
{
	int result = 0; // default value: cars are equal
	if (this->year > car.year) // left car is greater
	{
		result = 1;
	}
	else if (this->year < car.year) // right car is greater
	{
		result = -1;
	}

	return result;
}