#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class DataBaseHander
{

private:

public:

	unsigned int CostReaderInstitute(const string& city, const string& institute) const;
	unsigned int CostReaderTransport(const string& city, const string& district, const string& institute) const;
	unsigned int CostReaderCosts(const string& city, const string& age) const;
	unsigned int CostReaderCaffeAndCinema(const string& city, const string& adress, const string& caffe, const string& cinema) const;
};