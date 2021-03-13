#include "Student.h"

Student::Student
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
)
{

	_numberNonWorkDay = numberNonWorkDay;
	_numberWorkDay = numberWorkDay;
	_institute = institute;
	_district = district;
	_adress = adress;
	_cinema = cinema;
	_caffe = caffe;
	_city = city;
	_age = age;
}

unsigned int Student::CounterMonthCost(unsigned int numberWorkDay, unsigned int numberNonWorkDay)
{
	unsigned int costCaffeAndCinema;
	unsigned int costTransport;
	unsigned int costInstitute;
	unsigned int costCosts;
	unsigned int cost = 0;
	
	DataBaseHander data;

	costCaffeAndCinema = data.CostReaderCaffeAndCinema(_city, _adress, _caffe, _cinema, "Caffe-And-Cinema.csv");
	costTransport = data.CostReaderTransport(_city, _district, _institute, "Transport.csv");
	costInstitute = data.CostReaderInstitute(_city, _institute, "Institute.csv");
	costCosts = data.CostReaderCosts(_city, _age, "Costs.csv");

	if (costTransport != NULL && costInstitute != NULL && costCosts != NULL && costCaffeAndCinema != NULL) {

		cost = ((costTransport * 2 + costInstitute) * numberWorkDay + (costCaffeAndCinema) * numberNonWorkDay) + costCosts;
	}
	else {

		return cost;
	}

	return cost;
}