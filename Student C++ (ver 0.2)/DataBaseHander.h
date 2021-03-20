#pragma once

#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class DataBaseHander
{

private:

	struct Recreation {

		string city;
		string adress;
		string name;
		string cost;
	};

public:

	static unsigned int CostReaderInstitute(const string& city, const string& institute, const string& path);
	static unsigned int CostReaderCosts(const string& city, const string& age, const string& path);
	static unsigned int CostReaderTransport(const string& city, const string& district, const string& institute, const string& path);
	static unsigned int CostReaderCaffeAndCinema(const string& city, const string& adress, const string& caffe, const string& cinema, const string& path);
};