#pragma once
#include <iostream>
#include <string>
#include "DataBaseHander.h"

using namespace std;

class Student
{

private:

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
		
		unsigned int& numberWorkDay,
		unsigned int& numberNonWorkDay
	);

	unsigned int CounterMonthCost(const unsigned int& numberWorkDay, const unsigned int& numberNonWorkDay);

};