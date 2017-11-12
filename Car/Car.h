#pragma once
#include <iostream>
#include <string>

using namespace std;

#define SIZE_OF_COLOR 10

class Car
{
private:
	string make;
	string model;
	unsigned int year;
	double engineVolume;
	char color[SIZE_OF_COLOR];

public:
	Car();
	Car(string, string, unsigned int, double, char[SIZE_OF_COLOR]);
	
	void setMake(string);
	void setModel(string);
	void setYear(unsigned int);
	void setEngineVolume(double);
	void setColor(char[SIZE_OF_COLOR]);
	
	string getMake() const;
	string getModel() const;
	unsigned int getYear() const;
	double getEngineVolume() const;
	char* getColor();
	
	void print_car() const;
	int compare_by_year(const Car &) const;
	int compare_by_engine_volume(const Car &) const;
};