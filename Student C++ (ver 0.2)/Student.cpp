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
	unsigned int& numberWorkDay,
	unsigned int& numberNonWorkDay
)
{

	_age = age;
	_city = city;
	_institute = institute;
	_district = district;
	_adress = adress;
	_caffe = caffe;
	_cinema = cinema;
	_numberWorkDay = numberWorkDay;
	_numberNonWorkDay = numberNonWorkDay;
}

unsigned int Student::CounterMonthCost(const unsigned int& numberWorkDay, const unsigned int& numberNonWorkDay)
{
	unsigned int costTransport;
	unsigned int costInstitute;
	unsigned int costCosts;
	unsigned int costCaffeAndCinema;
	unsigned int cost = 0;

	DataBaseHander data;
	
	costTransport = data.CostReaderTransport(_city, _district, _institute);
	costInstitute = data.CostReaderInstitute(_city, _institute);
	costCosts = data.CostReaderCosts(_city, _age);
	costCaffeAndCinema = data.CostReaderCaffeAndCinema(_city, _adress, _caffe, _cinema);

	if (costTransport != NULL && costInstitute != NULL && costCosts != NULL && costCaffeAndCinema != NULL) {

		cost = (costTransport * 2 + costInstitute) * numberWorkDay + (costCaffeAndCinema) * numberNonWorkDay;
		cost = cost + costCosts;
	}
	else {

		cout << "Entered data incorect: " << endl;

		if (costTransport == NULL) {

			cout << "check positions: city, district, institute" << endl;
			exit(0);
		}

		if (costInstitute == NULL) {

			cout << "check positions: city, institute" << endl;
			exit(0);
		}

		if (costCosts == NULL) {

			cout << "check positions: city, age" << endl;
			exit(0);
		}

		if (costCaffeAndCinema == NULL) {

			cout << "check positions: city, adress, caffe, cinema" << endl;
			exit(0);
		}
	}

	return cost;
}