#include <iostream>
#include <string>
#include <assert.h>
#include "Car.h"

using namespace std;

#define SIZE_OF_COLOR 10

// constructor
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

string Car::getMake()
{
	return make;
}

string Car::getModel()
{
	return model;
}

unsigned int Car::getYear()
{
	return year;
}

double Car::getEngineVolume()
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
void Car::print_car()
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
Car* Car::compare_by_year(Car* car)
{
	assert(car != NULL);
	return (this->year > car->year) ? car : this;
}

/*
Compare two cars by engine volume
@param car - the second car to compare
@return the car that has a greater engine volume
*/
Car* Car::compare_by_engine_volume(Car* car)
{
	assert(car != NULL);
	return this->engineVolume > car->engineVolume ? this : car;
}
