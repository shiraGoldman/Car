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
	Car(string, string, unsigned int, double, char[SIZE_OF_COLOR]);
	
	void setMake(string);
	void setModel(string);
	void setYear(unsigned int);
	void setEngineVolume(double);
	void setColor(char[SIZE_OF_COLOR]);
	
	string getMake();
	string getModel();
	unsigned int getYear();
	double getEngineVolume();
	char* getColor();
	
	void print_car();
	Car* compare_by_year(Car*);
	Car* compare_by_engine_volume(Car*);
};