#pragma once
#include <iostream>
#include <string>
#include "DataBaseHander.h"

using namespace std;

class Student
{

private:

	/*const string& GetInstitute();
	const string& GetDistrict();
	const string& GetCinema();
	const string& GetAdress();
	const string& GetCaffe();
	const string& GetCity();
	const string& GetAge();*/

	string _name;
	string _city;
	string _institute;
	string _district;
	string _adress;
	string _caffe;
	string _cinema;
	string _age;

	unsigned int _numberWorkDay;
	unsigned int _numberNonWorkDay;

public:

	Student
	(
		const string& age,
		const string& name,
		const string& city,
		const string& institute,
		const string& district,
		const string& adress,
		const string& caffe,
		const string& cinema,
		
		unsigned int numberWorkDay,
		unsigned int numberNonWorkDay

	);

	unsigned int CounterMonthCost(unsigned int numberWorkDay, unsigned int numberNonWorkDay);

};